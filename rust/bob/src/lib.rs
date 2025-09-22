pub fn reply(message: &str) -> &str {
    let empty = message.trim().is_empty();
    let has_chars = message.chars().filter(char::is_ascii_alphabetic).count() > 0;
    let all_caps = message
        .chars()
        .filter(char::is_ascii_alphabetic)
        .all(char::is_uppercase);
    let question = message.trim().ends_with("?");

    match (empty, has_chars && all_caps, question) {
        (true, _, _) => "Fine. Be that way!",
        (_, true, true) => "Calm down, I know what I'm doing!",
        (_, _, true) => "Sure.",
        (_, true, _) => "Whoa, chill out!",
        _ => "Whatever.",
    }
}
