use std::sync::{Arc, Mutex};
use std::thread;
use std::time::Duration;

fn main() {
    let m = Arc::new(Mutex::new(0));
    let mut handles = Vec::new();
    for i in 1..10 {
        let m = Arc::clone(&m);
        let handle = thread::spawn(move || {
            let mut num = m.lock().unwrap();
            *num += 1;
        });
        handles.push(handle);
    }
    for handle in handles {
        handle.join().unwrap();
    }
    println!("m = {:?}", m);
}