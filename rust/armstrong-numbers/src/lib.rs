pub fn is_armstrong_number(num: u32) -> bool {
    let str = num.to_string();
    str.chars()
        .filter_map(|d| d.to_digit(10))
        .map(|d| d.pow(str.len() as u32))
        .sum::<u32>()
        == num
}
