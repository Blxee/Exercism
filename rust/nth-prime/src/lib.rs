pub fn nth(n: u32) -> u32 {
    let mut primes = Vec::new();
    (2..)
        .filter(|&i| {
            let sqrt = (i as f32).sqrt() as u32;
            let is_prime = primes
                .iter()
                .take_while(|&&j| j <= sqrt)
                .all(|j| i % j != 0);
            if is_prime {
                primes.push(i);
            }
            is_prime
        })
        .nth(n as usize)
        .unwrap()
}
