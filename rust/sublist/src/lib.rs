#[derive(Debug, PartialEq, Eq)]
pub enum Comparison {
    Equal,
    Sublist,
    Superlist,
    Unequal,
}

pub fn sublist(first_list: &[i32], second_list: &[i32]) -> Comparison {
    if first_list == second_list {
        return Comparison::Equal;
    }
    if second_list.is_empty() {
        return Comparison::Superlist;
    }
    if first_list.is_empty() {
        return Comparison::Sublist;
    }
    let a_in_b = second_list.windows(first_list.len()).any(|w| w == first_list);
    let b_in_a = first_list.windows(second_list.len()).any(|w| w == second_list);
    if b_in_a {
        return Comparison::Superlist;
    }
    if a_in_b {
        return Comparison::Sublist;
    }
    Comparison::Unequal
}
