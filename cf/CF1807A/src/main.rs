#[macro_use]
extern crate text_io;

fn main() {
    let T: i32 = read!();
    for t in 0..T {
        let a: i32 = read!();
        let b: i32 = read!();
        let c: i32 = read!();
        if a + b == c {
            println!("+");
        } else {
            println!("-");
        }
    }
}
