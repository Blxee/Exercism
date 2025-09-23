pub fn collatz(mut n: u64) -> Option<u64> {
    if n == 0 {
        return None;
    }

    let mut steps = 0;

    while n != 1 {
        n = match n % 2 == 0 {
            true => n / 2,
            false => n * 3 + 1,
        };
        steps += 1;
    }

    Some(steps)
}
