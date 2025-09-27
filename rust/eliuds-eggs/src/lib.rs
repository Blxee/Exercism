pub fn egg_count(mut display_value: u32) -> usize {
    let mut total = 0;
    while display_value > 0 {
        total += display_value as usize & 1;
        display_value >>= 1;
    }
    total
}
