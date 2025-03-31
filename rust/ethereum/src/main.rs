use ethers::prelude::*;
use ethers::providers::{Middleware, Provider, StreamExt, Http};
use std::sync::Arc;
use tokio;
use ethers::providers::Ws;

#[tokio::main]
async fn main() -> Result<(), Box<dyn std::error::Error>> {
    // Replace with your Ethereum RPC endpoint (Infura, Alchemy, or your own node)
    let provider = Arc::new(Provider::<Http>::try_from("https://hardhat.cookingwithbello.com/")?);

    // Get the latest block number
    let latest_block = provider.get_block_number().await?;
    let start_block = latest_block.as_u64().saturating_sub(20); // Get last 20 blocks

    println!("Fetching transactions from blocks {} to {}", start_block, latest_block);

    for block_number in start_block..=latest_block.as_u64() {
        if let Some(block) = provider.get_block_with_txs(block_number).await? {
            println!("Block #{} - {} transactions", block_number, block.transactions.len());

            for tx in block.transactions {
                println!(
                    "Tx Hash: {:?}, From: {:?}, To: {:?}, Value: {} ETH",
                    tx.hash,
                    tx.from,
                    tx.to.unwrap_or_else(|| Address::zero()), // Handle contract creations
                    ethers::utils::format_ether(tx.value)
                );
            }
        }
    }

    // Subscribe to mempool transactions using WebSocket
    println!("\nSubscribing to pending transactions in mempool...");

    let ws_provider = Arc::new(Provider::<Ws>::connect("wss://hardhat.cookingwithbello.com/").await?);
    let mut tx_stream = ws_provider.subscribe_pending_txs().await?;

    while let Some(tx_hash) = tx_stream.next().await {
        if let Ok(Some(tx)) = ws_provider.get_transaction(tx_hash).await {
            println!(
                "Mempool Tx Hash: {:?}, From: {:?}, To: {:?}, Value: {} ETH",
                tx.hash,
                tx.from,
                tx.to.unwrap_or_else(|| Address::zero()),
                ethers::utils::format_ether(tx.value)
            );
        }
    }
    Ok(())
}
