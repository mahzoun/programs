use std::sync::mpsc;
use std::thread;
use std::time::Duration;    

fn main() {
    let (tx, rx) = mpsc::channel();
    let tx1 = tx.clone();
    let handle = thread::spawn(move || {
        for i in 1..100 {
            let value = i;
            println!("hi number {} from the first spawned thread!", i);
            thread::sleep(Duration::from_millis(10));
            tx.send(value).unwrap();
        }
    });
    let handle1 = thread::spawn(move || {
        for i in 1..100 {
            let value = i*i;
            println!("hi number {} from the second spawned thread!", i);
            thread::sleep(Duration::from_millis(10));
            tx1.send(value).unwrap();
        }
    });
    for received in rx {
        println!("Got: {}", received);
    }
    handle.join().unwrap();
}