pub fn brackets_are_balanced(string: &str) -> bool {
    let mut stack = Vec::new();

    for chr in string.chars() {
        if let Some(i) = "([{".find(chr) {
            stack.push(i);
        } else if let Some(i) = ")]}".find(chr) {
            match stack.pop() {
                None => return false,
                Some(j) if j != i => return false,
                _ => (),
            }
        }
    }
    stack.is_empty()
}
