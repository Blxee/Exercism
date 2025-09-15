pub struct CircularBuffer<T> {
    capacity: usize,
    buffer: Box<[Option<T>]>,
    first: usize,
    last: usize,
}

#[derive(Debug, PartialEq, Eq)]
pub enum Error {
    EmptyBuffer,
    FullBuffer,
}

impl<T> CircularBuffer<T> {
    pub fn new(capacity: usize) -> Self {
        let mut buffer = Vec::with_capacity(capacity);
        buffer.resize_with(capacity, || None);
        let buffer = buffer.into_boxed_slice();
        let (first, last) = (0, 0);
        Self { capacity, buffer, first, last }
    }

    pub fn write(&mut self, element: T) -> Result<(), Error> {
        match self.buffer[self.last] {
            None => {
                self.buffer[self.last] = Some(element);
                self.last += 1;
                self.last %= self.capacity;
                Ok(())
            },
            Some(_) => Err(Error::FullBuffer)
        }
    }

    pub fn read(&mut self) -> Result<T, Error> {
        match self.buffer[self.first].take() {
            Some(val) => {
                self.first += 1;
                self.first %= self.capacity;
                Ok(val)
            },
            None => Err(Error::EmptyBuffer)
        }
    }

    pub fn clear(&mut self) {
        self.buffer.iter_mut().for_each(|e| *e = None);
    }

    pub fn overwrite(&mut self, element: T) {
        if let Some(_) = self.buffer[self.last].replace(element) {
            self.first += 1;
            self.first %= self.capacity;
        }
        self.last += 1;
        self.last %= self.capacity;
    }
}
