pub fn reply(message: &str) -> &str {
    let empty = message.trim().is_empty();
    let has_chars = message.chars().filter(char::is_ascii_alphabetic).count() > 0;
    let all_caps = message
        .chars()
        .filter(char::is_ascii_alphabetic)
        .all(char::is_uppercase);
    let is_question = message.trim().chars().last();

    match (empty, has_chars && all_caps, is_question) {
        (true, _, _) => "Fine. Be that way!",
        (_, true, Some('?')) => "Calm down, I know what I'm doing!",
        (_, _, Some('?')) => "Sure.",
        (_, true, _) => "Whoa, chill out!",
        _ => "Whatever.",
    }
}
