use std::collections::HashMap;

pub fn plants(diagram: &str, student: &str) -> Vec<&'static str> {
    let plants: HashMap<char, &'static str> = HashMap::from_iter([
        ('G', "grass"),
        ('C', "clover"),
        ('R', "radishes"),
        ('V', "violets"),
    ]);

    let get_student_pos = |student: &str| (student.as_bytes()[0] - b'A') as usize;

    let mut results = Vec::new();

    diagram.split('\n').for_each(|row| {
        let mut iter = row.chars().skip(get_student_pos(student) * 2);
        results.push(*plants.get(&iter.next().unwrap()).unwrap());
        results.push(*plants.get(&iter.next().unwrap()).unwrap());
    });

    results
}
