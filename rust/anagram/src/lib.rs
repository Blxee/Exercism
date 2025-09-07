use std::collections::HashSet;

pub fn anagrams_for<'a>(word: &str, possible_anagrams: &[&'a str]) -> HashSet<&'a str> {
    // todo!("For the '{word}' word find anagrams among the following words: {possible_anagrams:?}");
    let mut result = HashSet::new();
    let mut word_vec = word.to_lowercase().chars().collect::<Vec<_>>();
    word_vec.sort();

    for &cur in possible_anagrams {
        if word.to_lowercase() == cur.to_lowercase() {
            continue;
        }
        let mut cur_vec = cur.to_lowercase().chars().collect::<Vec<_>>();
        cur_vec.sort();
        if word_vec == cur_vec {
            result.insert(cur);
        }
    }
    result
}
