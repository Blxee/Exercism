pub fn build_proverb(list: &[&str]) -> String {
    let verse = |(word1, word2)| format!("For want of a {word1} the {word2} was lost.\n");
    let mut result: String = list.iter().zip(list.iter().skip(1)).map(verse).collect();
    if !list.is_empty() {
        result.push_str(&format!("And all for the want of a {}.", list[0]));
    }
    result
}
