pub fn annotate(garden: &[&str]) -> Vec<String> {
    let mut result = garden.iter().map(ToString::to_string).collect::<Vec<_>>();

    for y in 0..result.len() {
        for x in 0..result[y].len() {
            if result[y].bytes().nth(x).unwrap() == b'*' {
                add_to_adjacents(&mut result, (x, y));
            }
        }
    }
    result
}

fn add_to_adjacents(field: &mut [String], (x, y): (usize, usize)) {
    let x_start = if x > 0 { x - 1 } else { x };
    let x_end = if x < field[0].len() - 1 { x + 1 } else { x };
    let y_start = if y > 0 { y - 1 } else { y };
    let y_end = if y < field.len() - 1 { y + 1 } else { y };

    for x in x_start..=x_end {
        for y in y_start..=y_end {
            let square = get_square(field, (x, y));
            if *square == b' ' {
                *square = b'1';
            } else if *square != b'*' {
                *square += 1;
            }
        }
    }
}

fn get_square(field: &mut [String], (x, y): (usize, usize)) -> &mut u8 {
    unsafe { &mut field[y].as_bytes_mut()[x] }
}
