MatrixXd eulerAngle2Rot(double roll, double pitch, double yaw)
{
	MatrixXd R(3, 3);

	MatrixXd Rz(3, 3);
	MatrixXd Ry(3, 3);
	MatrixXd Rx(3, 3);

	double rRoll = deg2rad(roll);
	double rPitch = deg2rad(pitch);
	double rYaw = deg2rad(yaw);

	Rz(0,0) = cos(rYaw);	Rz(0,1) = -sin(rYaw);	Rz(0,2) = 0;
	Rz(1,0) = sin(rYaw);	Rz(1,1) = cos(rYaw);	Rz(1,2) = 0;
	Rz(2,0) = 0;			Rz(2,1) = 0;			Rz(2,2) = 1;

	Ry(0,0) = cos(rPitch);	Ry(0,1) = 0;			Ry(0,2) = sin(rPitch);
	Ry(1,0) = 0;			Ry(1,1) = 1;			Ry(1,2) = 0;
	Ry(2,0) = -sin(rPitch);	Ry(2,1) = 0;			Ry(2,2) = cos(rPitch);

	Rx(0,0) = 1;			Rx(0,1) = 0;			Rx(0,2) = 0;
	Rx(1,0) = 0;			Rx(1,1) = cos(rRoll);	Rx(1,2) = -sin(rRoll);
	Rx(2,0) = 0;			Rx(2,1) = sin(rRoll);	Rx(2,2) = cos(rRoll);


	R = Rx*Ry*Rz;

	return R;
}