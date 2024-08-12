#include "vtkStudy.h"

vtkStudy::vtkStudy(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//绘制常见的几何体
	DrawSphere();//绘制球体

}

vtkStudy::~vtkStudy()
{}

void vtkStudy::DrawSphere()
{
	// 创建一个球体源
	vtkSmartPointer<vtkSphereSource> sphereSource =
		vtkSmartPointer<vtkSphereSource>::New();
	sphereSource->SetCenter(0.0, 0.0, 0.0);  // 设置球体中心坐标
	sphereSource->SetRadius(2);  // 设置球体半径
	sphereSource->SetPhiResolution(100);  // 设置球体的纬线分辨率
	sphereSource->SetThetaResolution(100);  // 设置球体的经线分辨率
	sphereSource->Update();  // 更新球体数据
	sphereSources.push_back(sphereSource);
}



