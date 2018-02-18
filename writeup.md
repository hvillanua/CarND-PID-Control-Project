# **Behavioral Cloning**

## Rubric Points

### Describe the effect each of the P, I, D components had in your implementation.
I implemented 2 PID controllers, one for the steering angle and another one for the throttle. The idea behind this implementation
is to be able to drive at medium-high speed. To do this we need to be able to slow down on curves, since a single PID controller
on the steering angle won't be enough to keep the car in track at high speed.

The _P_ term affects how the signal reacts in proportion to the cte (cross-track error). The problem with a P controller is that
it takes some time to converge to the desired output as it keeps crossing the optimal value up and down.
To fix this problem we introduce the _D_ term, which reacts to the derivative of the signal within an interval t.
This helps us "anticipate" future changes and smooth the transition to the desired control value.
The _I_ term acts as a bias correction by working with the accumulated cte.

### Describe how the final hyperparameters were chosen.

For the steering control I opted for a PD controller, since we can safely assume that the car has no bias.
Parameters were manually chosen starting with the _P_ term and then the _D_ term. Since I was aiming for
relatively high speeds I settled with a low _P_ value to avoid excessive overshooting on curves, while the
_D_ value was set to make straight driving look smooth.

For the throttle control I ended up with a PID controller. Again, the parameters were chosen manually.
The _P_ value was set to brake when necessary to avoid high speeds on curves that would throw the vehicle
off the track. Both _D_ and _I_ were set to a value that experimentally made the driving fast, with as
little braking as necessary. The _I_ value was introduced to indicate that the car has a bias towards
accelerating, helping to prevent high speed turns.

