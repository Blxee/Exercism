pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let get_plant = |c| match c {
        'G' => "grass",
        'C' => "clover",
        'R' => "radishes",
        'V' => "violets",
        _ => panic!("No such plant!"),
    };

    let student_pos = (student.as_bytes()[0] - b'A') as usize;

    diagram
        .lines()
        .flat_map(|row| row.chars().skip(student_pos * 2).take(2))
        .map(get_plant)
        .collect()
}
