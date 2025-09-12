/// Check a Luhn checksum.
pub fn is_valid(code: &str) -> bool {
    if code.chars().filter(char::is_ascii_digit).count() <= 1 {
        return false;
    }
    code.chars().rev().try_fold((0u32, false), |(acc, should_x2), c| {
        if let Some(mut c) = c.to_digit(10) {
            if should_x2 {
                c *= 2;
            }
            if c > 9 {
                c -= 9;
            }
            Ok((acc + c, !should_x2))
        } else if c == ' ' {
            Ok((acc, should_x2))
        } else {
            Err(())
        }
    }).is_ok_and(|s| s.0 % 10 == 0)
}
