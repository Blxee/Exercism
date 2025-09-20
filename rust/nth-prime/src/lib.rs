pub fn nth(n: u32) -> u32 {
    (2..)
        .filter(|&i| (2..i).all(|j| i % j != 0))
        .nth(n as usize)
        .unwrap()
    // behold the sieve of eratosthesenuts:
    // let mut range: Box<dyn Iterator<Item = u32>> = Box::new(2..);
    // for i in 2..((n + 1).pow(2)) {
    //     range = Box::new(range.filter(move |&j| i == j || j % i != 0));
    // }
    // range.nth(n as usize).unwrap()
}
