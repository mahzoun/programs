use std::thread;
use std::time::Duration;
fn main() {
    let mut v: Vec<i32> = Vec::new();
    for i in 1..101 {
        v.push(i*2);
    }
    let handle = thread::spawn(move || {
        for i in 1..100 {
            v[1] += 2;
            println!("hi number {} from the spawned thread!", v[1]);
            thread::sleep(Duration::from_millis(1));
        }
    });
    for i in 1..10 {
        println!("hi number {} from the main thread!", i);
        thread::sleep(Duration::from_millis(1));
    }
    handle.join().unwrap();
}
