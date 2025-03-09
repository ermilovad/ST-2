// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include "circle.h"
#include "tasks.h"
#include <cmath>
#include <stdexcept>

TEST(test, can_create_circle) {
	ASSERT_NO_THROW(Circle(6.2));
}

TEST(test, cant_create_circle_incorrect_size) {
	EXPECT_THROW(Circle(-5.0), std::invalid_argument);
}

TEST(test, cant_change_radius_incorrect_size) {
	Circle A(50.0);
	double a = -40.0;
	EXPECT_THROW(A.setArea(a), std::invalid_argument);
}
TEST(test, cant_change_ference_incorrect_size) {
	Circle A(50.0);
	double a = -70.0;
	EXPECT_THROW(A.setFerence(a), std::invalid_argument);
}
TEST(test, cant_change_area_incorrect_size) {
	Circle A(50.0);
	double a = -20.0;
	EXPECT_THROW(A.setArea(a), std::invalid_argument);
}

TEST(test, can_set_redius) {
	Circle A;
	ASSERT_NO_THROW(A.setRadius(7.0));
}
TEST(test, can_set_ference) {
	Circle A;
	ASSERT_NO_THROW(A.setFerence(9.6));
}
TEST(test, can_set_area) {
	Circle A;
	ASSERT_NO_THROW(A.setArea(11.2));
}
TEST(test, can_get_radius) {
	Circle A(7.0);
	EXPECT_NEAR(A.getRadius(), 7.0);
}
TEST(test, can_get_ference) {
	Circle A(3.0);
	EXPECT_NEAR(A.getFerence(), 2 * pi * 3.0, 1e-6);
}
TEST(test, can_get_area) {
	Circle A(6.5);
	EXPECT_NEAR(A.getArea(), pi * 6.5 * 6.5, 1e-6);
}

TEST(test, can_create_circle_small_radius) {
	double r = 0.0000004;
	Circle A(r);
	EXPECT_NEAR(A.getRadius(), r);
	EXPECT_NEAR(A.getFerence(), 2 * pi * r, 1e-6);
	EXPECT_NEAR(A.getArea(), pi * r * r, 1e-6);
}
TEST(test, can_create_circle_large_radius) {
	double r = 100000.0;
	Circle A(r);
	EXPECT_NEAR(A.getRadius(), r);
	EXPECT_NEAR(A.getFerence(), 2 * pi * r, 1e-6);
	EXPECT_NEAR(A.getArea(), pi * r * r, 1e-6);
}

TEST(test, can_create_circle_0_radius) {
	double r = 0.0;
	Circle A(r);
	EXPECT_NEAR(A.getRadius(), r);
	EXPECT_NEAR(A.getFerence(), r, 1e-6);
	EXPECT_NEAR(A.getArea(), r, 1e-6);
}
TEST(test, can_change_radius) {
	Circle A(50.0);
	double r = 40.0;
	A.setRadius(r);
	EXPECT_NEAR(A.getRadius(), r);
	EXPECT_NEAR(A.getFerence(), 2 * pi * r, 1e-6);
	EXPECT_NEAR(A.getArea(), pi * r * r, 1e-6);
}
TEST(test, can_change_ference) {
	Circle A(50.0);
	double f = 40.0;
	A.setFerence(f);
	EXPECT_NEAR(A.getFerence(), f);
	EXPECT_NEAR(A.getRadius(), f / (2 * pi), 1e-6);
	EXPECT_NEAR(A.getArea(), pi * A.getRadius() * A.getRadius(), 1e-6);
}
TEST(test, can_change_area) {
	Circle A(50.0);
	double a = 40.0;
	A.setArea(a);
	EXPECT_NEAR(A.getArea(), a);
	EXPECT_NEAR(A.getRadius(), std::sqrt(a / pi), 1e-6);
	EXPECT_NEAR(A.getFerence(), 2 * pi * A.getRadius(), 1e-6);
}

TEST(test, can_change_ference_0) {
	Circle A(50.0);
	double f = 0.0;
	A.setFerence(f);
	EXPECT_NEAR(A.getFerence(), f);
	EXPECT_NEAR(A.getRadius(), f);
	EXPECT_NEAR(A.getArea(), f);
}
TEST(test, can_change_area) {
	Circle A(50.0);
	double a = 0.0;
	A.setArea(a);
	EXPECT_NEAR(A.getArea(), a);
	EXPECT_NEAR(A.getRadius(), a);
	EXPECT_NEAR(A.getFerence(), a);
}

TEST(test, task_ground_rope) {
	double res = CalculateGroundRope();
	EXPECT_NEAR(res, 0.1591549431, 1e-6);
}

TEST(test, task_pool) {
	double res = CalculatePoolCost();
	EXPECT_NEAR(res, 72256.63103, 1e-6);
}