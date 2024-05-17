from py_ecc import bn128
from web3 import Web3
import random

def pedersen_commitment(g, h, value, blinding_factor):
    return bn128.add(bn128.multiply(g, value), bn128.multiply(h, blinding_factor))

def generate_parameters():
    g = bn128.G1
    h = bn128.multiply(bn128.G1, random.randint(1, bn128.curve_order))
    return g, h

def main():
    value = 12345
    blinding_factor = random.randint(1, bn128.curve_order)
    g, h = generate_parameters()
    commitment = pedersen_commitment(g, h, value, blinding_factor)
    print(f"Commitment: {commitment}")

if __name__ == "__main__":
    main()