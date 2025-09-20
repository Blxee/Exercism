pub fn factors(mut n: u64) -> Vec<u64> {
    let mut primes = Vec::new();

    for i in 2..=n {
        let sqrt = (i as f32).sqrt() as u64;
        let is_prime = primes
            .iter()
            .take_while(|&&j| j <= sqrt)
            .all(|&j| i % j != 0);
        if is_prime {
            primes.push(i);
        }
    }

    let mut facts = Vec::new();

    for p in primes {
        while n != 0 && n % p == 0 {
            facts.push(p);
            n /= p;
        }
    }

    facts
}
