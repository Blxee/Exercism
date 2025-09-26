pub fn series(digits: &str, len: usize) -> Vec<String> {
    digits
        .chars()
        .collect::<Vec<_>>()
        .windows(len)
        .map(|win| String::from_iter(win))
        .collect()
}
