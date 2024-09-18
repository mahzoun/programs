
use std::io;

fn main() {
    let stdin = io::stdin();
    let mut input = String::new();
    stdin.read_line(&mut input).expect("Fail to read line");
    let n: u32 = input.trim().parse().expect("Expect an integer");
    for i in 0..n {
        input.clear();
        stdin.read_line(&mut input).expect("Fail to read line");
        let values: Vec<i32>  = input.trim().split_whitespace().map(|s| s.parse().expect("Please enter valid integers")).collect();
        if values[1] < -1 {
            println!("NO");
        } else {
            println!("YES");
        }
    }
}
