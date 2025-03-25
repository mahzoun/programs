use std::env;
use std::error::Error;
use std::fs;


pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;
    let results = if config.ignore_case {
        search_insensitive(&config.query, &contents)
    } else {
        search(&config.query, &contents)
    };
    for line in results {
        println!("{}", line);
    }
    Ok(())
}

pub fn search<'a>(query: &'a str, contents: &'a str) -> Vec<&'a str> {
    contents.lines().filter(|line| line.contains(query)).collect()
}

pub fn search_insensitive<'a>(query: &'a str, contents: &'a str) -> Vec<&'a str> {
    let qury = query.to_lowercase();
    contents.lines().filter(|line| line.to_lowercase().contains(&qury)).collect()
}

pub struct Config {
    pub query: String,
    pub filename: String,
    pub ignore_case: bool,
}

impl Config {
    pub fn build(mut args: impl Iterator<Item = String>) -> Result<Config, &'static str> {
        args.next();
        let query = args.next().ok_or("Missing query string")?;
        let filename = args.next().ok_or("Missing filename")?;
        let ignore_case = env::var("IGNORE_CASE").is_ok();
        Ok(Config {
            query,
            filename,
            ignore_case,
        })
    }
}

#[cfg(test)]

mod tests {
    use super::*;

    #[test]
    fn one_result() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }

    #[test]
    fn case_sensitive() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.
Duct tape.";
        assert_eq!(vec!["safe, fast, productive."], search(query, contents));
    }

    #[test]
    fn case_insensitive() {
        let query = "rUsT";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.
Duct tape.";
        assert_eq!(vec!["Rust:"], search_insensitive(query, contents));
    }
}
