#[derive(Debug)]
/// An event in the elevator system that the controller must react to.
enum Event {
    success,

}

/// A direction of travel.
#[derive(Debug)]
enum Direction {
    Up,
    Down,
}

/// The car has arrived on the given floor.
fn car_arrived(floor: i32) -> Event {
    Event::success
}

/// The car doors have opened.
fn car_door_opened() -> Event {
    Event::success
}

/// The car doors have closed.
fn car_door_closed() -> Event {
    Event::success
}

/// A directional button was pressed in an elevator lobby on the given floor.
fn lobby_call_button_pressed(floor: i32, dir: Direction) -> Event {
    Event::success
}

/// A floor button was pressed in the elevator car.
fn car_floor_button_pressed(floor: i32) -> Event {
    Event::success
}

fn main() {
    let opt = Some(123);
    match opt {
        outer @ Some(inner) => {
            println!("outer: {outer:?}, inner: {inner}");
        }
        None => {}
    };

    println!(
        "A ground floor passenger has pressed the up button: {:?}",
        lobby_call_button_pressed(0, Direction::Up)
    );
    println!("The car has arrived on the ground floor: {:?}", car_arrived(0));
    println!("The car door opened: {:?}", car_door_opened());
    println!(
        "A passenger has pressed the 3rd floor button: {:?}",
        car_floor_button_pressed(3)
    );
    println!("The car door closed: {:?}", car_door_closed());
    println!("The car has arrived on the 3rd floor: {:?}", car_arrived(3));
}