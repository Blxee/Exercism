pub fn factors(mut n: u64) -> Vec<u64> {
    let mut facts = Vec::new();

    let mut i = 2;
    while i <= n {
        while n != 0 && n % i == 0 {
            facts.push(i);
            n /= i;
        }
        i += 1;
    }

    facts
}
