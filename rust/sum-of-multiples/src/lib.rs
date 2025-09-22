use std::collections::HashSet;

pub fn sum_of_multiples(limit: u32, factors: &[u32]) -> u32 {
    factors
        .into_iter()
        .fold(HashSet::new(), |mut set, &val| {
            if val > 0 {
                set.extend((val..limit).step_by(val as usize));
            }
            set
        })
        .into_iter()
        .sum()
}
