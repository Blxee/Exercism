pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    (0..limit)
        .filter(|&i| factors.iter().any(|&v| v != 0 && i % v == 0))
        .sum()
}
