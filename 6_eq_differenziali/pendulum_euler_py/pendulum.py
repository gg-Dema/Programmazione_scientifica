import numpy as np
from scipy import integrate


def int_pendulum_sim(theta_init, t, L=1, m=1, b=0, g=9.81):
    theta_dot_1 = theta_init[1]
    theta_dot_2 = -b/m * theta_init[1] - g/L * np.sin(theta_init[0])
    return theta_dot_1, theta_dot_2

def euler_pendulum_sim(theta_init, t, L=1, m=1, b=0, g=9.81):
    theta1 = [theta_init[0]]
    theta2 = [theta_init[1]]
    dt = t[1] - t[0]
    for i, t_ in enumerate(t[:-1]):
        next_theta1 = theta1[-1] + theta2[-1] * dt
        next_theta2 = theta2[-1] - (b/(m*L**2) * theta2[-1] - g/L * np.sin(next_theta1))*dt

        theta1.append(next_theta1)
        theta2.append(next_theta2)
    return np.stack([theta1, theta2]).T

if __name__ == "__main__":

    mass = 1  # (kg)
    lenght = 2  # (m)
    b = 0  # (kg / m^2 -s)
    g = 9.81   # (gravity)
    delta_t = 0.001 # (second)
    T = 10  # (second)
    theta1_0 = np.pi/2  # (initial angle) (radiants)
    theta2_0 = 0  # (initial angular velocity) (rad/sec)
    theta_init = (theta1_0, theta2_0)
    # discretize time
    t = np.linspace(0, T, int(T/delta_t))

    # simulation by scipy:
    theta_vals_int = integrate.odeint( int_pendulum_sim, theta_init, t)

    # euler method:
    # expand in TSE (taylor series) and truncate
    theta_vals_euler = euler_pendulum_sim(theta_init, t)


    mse_position = np.power(
        theta_vals_int[:, 0] - theta_vals_euler[:, 0], 2
    ).mean()
    mse_velocity = np.power(
        theta_vals_int[:, 1] - theta_vals_euler[:, 1], 2
    ).mean()
    print("MSE Position:\t{:.4f}".format(mse_position))
    print("MSE Velocity:\t{:.4f}".format(mse_velocity))




