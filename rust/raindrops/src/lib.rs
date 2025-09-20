pub fn raindrops(n: u32) -> String {
    const MAP: [(u32, &str); 3] = [(3, "Pling"), (5, "Plang"), (7, "Plong")];
    let mut result = String::new();

    for (i, str) in MAP {
        if n % i == 0 {
            result.push_str(str);
        }
    }

    if result.is_empty() {
        n.to_string()
    } else {
        result
    }
}
