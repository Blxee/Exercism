#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    IncompleteNumber,
}

/// Convert a list of numbers to a stream of bytes encoded with variable length encoding.
pub fn to_bytes(values: &[u32]) -> Vec<u8> {
    let mut total = Vec::new();

    for &(mut num) in values {
        let mut bytes = Vec::new();
        loop {
            bytes.push((num & 0b1111111 | 0b10000000) as u8);
            num >>= 7;
            if num == 0 {
                break;
            }
        }
        bytes.reverse();
        bytes.last_mut().map(|b| *b &= 0b01111111);
        total.extend(bytes);
    }

    total
}

/// Given a stream of bytes, extract all numbers which are encoded in there.
pub fn from_bytes(bytes: &[u8]) -> Result<Vec<u32>, Error> {
    let mut values = Vec::new();
    let mut num = 0u32;
    let mut incomplete = false;
    for &byte in bytes {
        num <<= 7;
        num |= (byte & 0b01111111) as u32;
        incomplete = true;
        if byte & 0b10000000 == 0 {
            values.push(num);
            num = 0;
            incomplete = false;
        }
    }
    if incomplete {
        Err(Error::IncompleteNumber)
    } else {
        Ok(values)
    }
}
