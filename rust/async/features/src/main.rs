use trpl::{Either, Html};

async fn page_title(url: &str) -> (&str, Option<String>) {
    let response = trpl::get(url).await.text().await;
    let title = Html::parse(&response)
        .select_first("title")
        .map(|title| title.inner_html());
    (url, title)
}

fn main() {
    let args = std::env::args().collect::<Vec<String>>();
    trpl::run(async {
        let title_fut_1 = page_title(&args[1]);
        let title_fut_2 = page_title(&args[2]);
        let (url, maybe_title) =
            match trpl::race(title_fut_1, title_fut_2).await {
                Either::Left(left) => left,
                Either::Right(right) => right,
            };
        println!("URL: {}", url);
        match maybe_title {
            Some(title) => println!("Title: {}", title),
            None => println!("No title found"),
        }
    })
}
