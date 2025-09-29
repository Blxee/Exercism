pub fn abbreviate(phrase: &str) -> String {
    dbg!(phrase);
    phrase
        .chars()
        .filter(|&c| " -".contains(c) || c.is_alphabetic())
        .collect::<Vec<_>>()
        .windows(2)
        .enumerate()
        .filter_map(|(i, w)| {
            if w[1].is_alphabetic()
                && (!w[0].is_alphabetic() || (w[0].is_lowercase() && w[1].is_uppercase()))
            {
                if i == 0 && w[0].is_alphabetic() {
                    return Some(vec![w[0], w[1]]);
                }
                Some(vec![w[1]])
            } else {
                if i == 0 && w[0].is_alphabetic() {
                    return Some(vec![w[0]]);
                }
                None
            }
        })
        .flatten()
        .map(|c| c.to_ascii_uppercase())
        .collect()
}
