pub fn recite(start_bottles: u32, take_down: u32) -> String {
    let count = [
        "no", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
    ];

    let mut song = String::new();

    for i in ((start_bottles - take_down + 1)..=start_bottles).rev() {
        let i = i as usize;
        let verse = format!(
            "

{0} green bottle{2} hanging on the wall,
{0} green bottle{2} hanging on the wall,
And if one green bottle should accidentally fall,
There'll be {1} green bottle{3} hanging on the wall.",
            count[i],
            count[i - 1].to_lowercase(),
            if i == 1 { "" } else { "s" },
            if i - 1 == 1 { "" } else { "s" },
        );
        song.push_str(&verse);
    }
    song.trim().to_string()
}
