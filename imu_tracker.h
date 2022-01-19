#ifndef __IMU_TRACKER_H__
#define __IMU_TRACKER_H__

#include <chrono>
#include "Eigen/Geometry"

namespace estimation
{
  using Ctime = std::chrono::steady_clock::time_point;

  // Returns a quaternion representing the same rotation as the given 'angle_axis' vector.
  template <typename T>
  Eigen::Quaternion<T> AngleAxisVectorToRotationQuaternion(const Eigen::Matrix<T, 3, 1> &angle_axis)
  {
    T scale = T(0.5);
    T w = T(1.);
    constexpr double kCutoffAngle = 1e-8; // We linearize below this angle.
    if (angle_axis.squaredNorm() > kCutoffAngle)
    {
      const T norm = angle_axis.norm();
      scale = sin(norm / 2.) / norm;
      w = cos(norm / 2.);
    }
    const Eigen::Matrix<T, 3, 1> quaternion_xyz = scale * angle_axis;
    return Eigen::Quaternion<T>(w, quaternion_xyz.x(), quaternion_xyz.y(), quaternion_xyz.z());
  }

  /*
      维护robot状态
      静止时,更新imu零漂情况；运动时,补偿
   */
  class ImuZeroDriftCompensation
  {
  public:
    ImuZeroDriftCompensation(Ctime time = std::chrono::steady_clock::now(),
                             const Eigen::Vector3d &filter_outlier_threshold = Eigen::Vector3d(0.1, 0.1, 0.1));
    void updateStateMachine(bool is_static_now);
    void calculateAndAddZeroDriftCompensation(Eigen::Quaterniond& orientation);

  private:
    bool filterIfOutlier(const Eigen::Quaterniond &orientation);
    void prepareForCalculateAngularVelocityCompensation(const Eigen::Quaterniond& orientation);
    void updateZeroDriftAngularVelocityCompensation(const Eigen::Quaterniond &orientation);
    void addZeroDriftCompensation(Eigen::Quaterniond& orientation);

  private:
    bool debug_{true};
    // state machine
    bool last_is_static_{false};
    bool record_for_calculate_angular_velocity_{false};       // record quat_start_statistic_
    bool need_update_zero_drift_compensation_{false};         // need update zero drift compensation
    Ctime time_for_start_static_;

    Ctime time_start_statistic_;                              // 开始统计时间
    Eigen::Quaterniond quat_start_statistic_;                 // 静止时，开始角度
    Eigen::Quaterniond last_compensatoin_end_;                // 上次补偿终点
    Eigen::Vector3d filter_outlier_threshold_;                // 过滤异常值阈值

    Ctime last_time_update_compensatoin_;                     // 上次补偿时间
    Eigen::Vector3d cur_angular_velocity_compensation_;       // 当前补偿的角速度
    Eigen::Quaterniond previous_zero_drift_compensation_;     // 累计的零漂补偿角度
  };

  // Keeps track of the orientation using angular velocities and linear
  // accelerations from an IMU. Because averaged linear acceleration (assuming
  // slow movement) is a direct measurement of gravity, roll/pitch does not drift,
  // though yaw does.
  /*
      使用IMU的角速度和线性加速度来跟踪方向。
      因为平均线性加速度(假设运动缓慢)是重力的直接测量，所以横滚/俯仰不会漂移，但偏航会。
   */
  class ImuGravityCorrection
  {
  public:
    ImuGravityCorrection(double imu_gravity_time_constant = 0.3f, Ctime time = std::chrono::steady_clock::now());

    // Advances to the given 'time' and updates the orientation to reflect this.
    void Advance(Ctime time);
    void Advance();

    // Updates from an IMU reading (in the IMU frame).
    // 根据传感器读数更新传感器的最新状态，得到经过重力校正的线加速度、角速度等。
    void AddImuLinearAccelerationObservation(const Eigen::Vector3d &imu_linear_acceleration);
    void AddImuAngularVelocityObservation(const Eigen::Vector3d &imu_angular_velocity);

    // Query the current time.
    Ctime time() const { return time_; }

    // Query the current orientation estimate.
    Eigen::Quaterniond orientation() const { return orientation_; }

  private:
    const double imu_gravity_time_constant_; // align重力的时间间隔
    Ctime time_;
    Ctime last_linear_acceleration_time_;
    Eigen::Quaterniond orientation_;       // 当前姿态
    Eigen::Vector3d gravity_vector_;       // 当前重力方向
    Eigen::Vector3d imu_angular_velocity_; // 角速度
  };
}

#endif