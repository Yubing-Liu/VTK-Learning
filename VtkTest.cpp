#include "VtkTest.h"

decltype(auto) ReadStep(const char* file) {
	STEPControl_Reader readerSTEP;
	IFSelect_ReturnStatus statSTEP = readerSTEP.ReadFile(file);
	IFSelect_PrintCount modeSTEP = IFSelect_ListByItem;
	readerSTEP.PrintCheckLoad(Standard_False, modeSTEP);
	readerSTEP.TransferRoots();
	TopoDS_Shape shape = readerSTEP.OneShape();

	vtkNew<vtkPolyDataMapper> mapper;
	vtkNew<vtkActor> actor;
	vtkNew<IVtkTools_ShapeDataSource> shapeSource; //创建一个可以被VTK使用的OCC数据源

	shapeSource->SetShape(new IVtkOCC_Shape(shape));//将shape添加到数据源中
	shapeSource->Update();
	mapper->SetInputConnection(shapeSource->GetOutputPort());
	

	actor->SetMapper(mapper);
	return actor;
}

decltype(auto) ReadVtk(const char* file) {
	vtkSmartPointer<vtkUnstructuredGridReader> vtkReader = vtkSmartPointer<vtkUnstructuredGridReader>::New();
	vtkReader->SetFileName(file);//读取VTK格式文件
	
	//将vtkUnstructuredGrid转换为vtkPolyData 
	vtkSmartPointer<vtkGeometryFilter> surfaceFilter =vtkSmartPointer<vtkGeometryFilter>::New();
	surfaceFilter->SetInputConnection(vtkReader->GetOutputPort());
	surfaceFilter->Update();
	
	vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();
		
	
	mapper->SetInputConnection(surfaceFilter->GetOutputPort());
	vtkSmartPointer<vtkActor> actor =vtkSmartPointer<vtkActor>::New();
	actor->SetMapper(mapper);
	return actor;

}

VtkTest::VtkTest(QWidget* parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	auto stepActor = ReadStep("D:/learn-git/VTK-Learning/VtkTest/Data/xjtu_full.STEP");
	auto vkt_Actor = ReadVtk("D:/learn-git/VTK-Learning/VtkTest/Data/xjtu_full.vtk");

	// 设置Actor的颜色为红色
	stepActor->GetProperty()->SetColor(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0);
	vkt_Actor->GetProperty()->SetColor(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0);

	// 创建vtkRenderer对象，并设置背景颜色为黑色
	vtkSmartPointer<vtkRenderer> renderer1 = vtkSmartPointer<vtkRenderer>::New();
	renderer1->SetBackground(0, 0, 0);
	vtkSmartPointer<vtkRenderer> renderer2 = vtkSmartPointer<vtkRenderer>::New();
	renderer2->SetBackground(0, 0, 0);

	// 将Actor添加到Renderer中
	renderer1->AddActor(stepActor);
	renderer1->SetViewport(0, 0, 0.5, 1);
	renderer2->AddActor(vkt_Actor);
	renderer2->SetViewport(0.5,0 , 1, 1);

	// 创建vtkGenericOpenGLRenderWindow对象，并将Renderer设置为其Renderer
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	renderWindow->AddRenderer(renderer1);
	renderWindow->AddRenderer(renderer2);

	// 将vtkGenericOpenGLRenderWindow对象设置为Qt界面上的RenderWindow
	ui.widget->setRenderWindow(renderWindow);

}

VtkTest::~VtkTest()
{}





