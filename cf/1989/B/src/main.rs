use std::io;
 
#[derive(Default)]
struct Scanner {
    buffer: Vec<String>,
}
impl Scanner {
    fn next<T: std::str::FromStr>(&mut self) -> T {
        loop {
            if let Some(token) = self.buffer.pop() {
                return token.parse().ok().expect("Failed parse");
            }
            let mut input = String::new();
            io::stdin().read_line(&mut input).expect("Failed read");
            self.buffer = input.split_whitespace().rev().map(String::from).collect();
        }
    }
}

fn main() {
    let mut scanner = Scanner::default();
    let t = scanner.next::<usize>();
    for i in 0..t{
        let mut over_lap:usize = 0;
        let a = scanner.next::<String>();
        let b = scanner.next::<String>();
        for l in 0..b.len() {
            let mut p = l;
            for &c in a.as_bytes().iter() {
                if p < b.len() && c == b.as_bytes()[p] {
                    p += 1;
                }
            }
            over_lap = over_lap.max(p - l);
            // println!("{a}, {b}, {over_lap}")
        }
        println!("{}", a.len() + b.len() - over_lap);
    }
}