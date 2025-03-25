/// A node in the binary tree.
use std::cmp::Ordering;
use std::fmt::Debug;
#[derive(Debug)]
struct Node<T: Ord + Debug> {
    value: T,
    left: Subtree<T>,
    right: Subtree<T>,
}

/// A possibly-empty subtree.
#[derive(Debug)]
struct Subtree<T: Ord + Debug>(Option<Box<Node<T>>>);

/// A container storing a set of values, using a binary tree.
///
/// If the same value is added multiple times, it is only stored once.
#[derive(Debug)]
pub struct BinaryTree<T: Ord + Debug> {
    root: Subtree<T>,
}

impl<T: Ord + Debug> BinaryTree<T> {
    fn new() -> Self {
        Self { root: Subtree::new() }
    }

    fn insert(&mut self, value: T) {
        self.root.insert(value);
    }

    fn has(&self, value: &T) -> bool {
        self.root.has(value)
    }

    fn len(&self) -> usize {
        self.root.len()
    }

    fn in_order(&self) {
        self.root.in_order()
    }
}

// Implement `new`, `insert`, `len`, and `has` for `Subtree`.
impl<T: Ord + Debug> Subtree<T> {
    fn new() -> Self {
        Self (None)
    }
    fn insert(&mut self, value: T) {
        match &mut self.0 {
            None => self.0 = Some(Box::new(Node::new(value))),
            Some(node) => match value.cmp(&node.value) {
                Ordering::Less => node.left.insert(value),
                Ordering::Equal => {}
                Ordering::Greater => node.right.insert(value),
            }
        }
    }
    fn has(&self, value: &T) -> bool {
        match &self.0 {
            None => false,
            Some(node) => match value.cmp(&node.value) {
                Ordering::Less => node.left.has(value),
                Ordering::Equal => true,
                Ordering::Greater => node.right.has(value),
            }
        }
    }
    fn len(&self) -> usize {
        match &self.0 {
            None => 0,
            Some(node) => 1 + node.left.len() + node.right.len(),
        }
    }
    fn in_order(&self) {
        match &self.0 {
            None => {},
            Some(node) => {
                node.left.in_order();
                dbg!(&node.value);
                node.right.in_order();
            }
        }
    }
}

impl<T: Ord + Debug> Node<T> {
    fn new(value: T) -> Self {
        Self {value: value, left: Subtree::new(), right: Subtree::new()}
    } 
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn len() {
        let mut tree = BinaryTree::new();
        assert_eq!(tree.len(), 0);
        tree.insert(2);
        assert_eq!(tree.len(), 1);
        tree.insert(1);
        assert_eq!(tree.len(), 2);
        tree.insert(2); // not a unique item
        assert_eq!(tree.len(), 2);
        for i in 0..10 {
            tree.insert(i);
        }
        tree.in_order();
    }

    #[test]
    fn has() {
        let mut tree = BinaryTree::new();
        fn check_has(tree: &BinaryTree<i32>, exp: &[bool]) {
            let got: Vec<bool> =
                (0..exp.len()).map(|i| tree.has(&(i as i32))).collect();
            assert_eq!(&got, exp);
        }

        check_has(&tree, &[false, false, false, false, false]);
        tree.insert(0);
        check_has(&tree, &[true, false, false, false, false]);
        tree.insert(4);
        check_has(&tree, &[true, false, false, false, true]);
        tree.insert(4);
        check_has(&tree, &[true, false, false, false, true]);
        tree.insert(3);
        check_has(&tree, &[true, false, false, true, true]);
    }

    #[test]
    fn unbalanced() {
        let mut tree = BinaryTree::new();
        for i in 0..100 {
            tree.insert(i);
        }
        assert_eq!(tree.len(), 100);
        assert!(tree.has(&50));
    }
}