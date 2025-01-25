#ifndef _COMMON_INC_COMMON_STATE_STATE_H__
#define _COMMON_INC_COMMON_STATE_STATE_H__

#include "common/basics/basics.h"

namespace common {
struct State {  // common::state
  decimal_t time_stamp{0.0}; // 时间戳
  Vecf<2> vec_position{Vecf<2>::Zero()};  // 2d 位置 (x, y)
  decimal_t angle{0.0};  // 朝向 theta_x
  decimal_t curvature{0.0};
  decimal_t velocity{0.0};
  decimal_t acceleration{0.0};
  decimal_t steer{0.0};  // 具体指什么
  void print() const {
    printf("State:\n");
    printf(" -- time_stamp: %lf.\n", time_stamp);
    printf(" -- vec_position: (%lf, %lf).\n", vec_position[0], vec_position[1]);
    printf(" -- angle: %lf.\n", angle);
    printf(" -- curvature: %lf.\n", curvature);
    printf(" -- velocity: %lf.\n", velocity);
    printf(" -- acceleration: %lf.\n", acceleration);
    printf(" -- steer: %lf.\n", steer);
  }

  Vec3f ToXYTheta() const {
    return Vec3f(vec_position(0), vec_position(1), angle);
  }

  EIGEN_MAKE_ALIGNED_OPERATOR_NEW  // 自动重载 new 和 delete 操作符，以确保内存分配是对齐的。
};

}  // namespace common

#endif  // _COMMON_INC_COMMON_STATE_STATE_H__
