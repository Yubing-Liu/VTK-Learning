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
	vtkNew<IVtkTools_ShapeDataSource> shapeSource; //����һ�����Ա�VTKʹ�õ�OCC����Դ

	shapeSource->SetShape(new IVtkOCC_Shape(shape));//��shape��ӵ�����Դ��
	shapeSource->Update();
	mapper->SetInputConnection(shapeSource->GetOutputPort());
	

	actor->SetMapper(mapper);
	return actor;
}

decltype(auto) ReadVtk(const char* file) {
	vtkSmartPointer<vtkUnstructuredGridReader> vtkReader = vtkSmartPointer<vtkUnstructuredGridReader>::New();
	vtkReader->SetFileName(file);//��ȡVTK��ʽ�ļ�
	
	//��vtkUnstructuredGridת��ΪvtkPolyData 
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

	// ����Actor����ɫΪ��ɫ
	stepActor->GetProperty()->SetColor(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0);
	vkt_Actor->GetProperty()->SetColor(255.0 / 255.0, 0.0 / 255.0, 0.0 / 255.0);

	// ����vtkRenderer���󣬲����ñ�����ɫΪ��ɫ
	vtkSmartPointer<vtkRenderer> renderer1 = vtkSmartPointer<vtkRenderer>::New();
	renderer1->SetBackground(0, 0, 0);
	vtkSmartPointer<vtkRenderer> renderer2 = vtkSmartPointer<vtkRenderer>::New();
	renderer2->SetBackground(0, 0, 0);

	// ��Actor��ӵ�Renderer��
	renderer1->AddActor(stepActor);
	renderer1->SetViewport(0, 0, 0.5, 1);
	renderer2->AddActor(vkt_Actor);
	renderer2->SetViewport(0.5,0 , 1, 1);

	// ����vtkGenericOpenGLRenderWindow���󣬲���Renderer����Ϊ��Renderer
	vtkSmartPointer<vtkGenericOpenGLRenderWindow> renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	renderWindow->AddRenderer(renderer1);
	renderWindow->AddRenderer(renderer2);

	// ��vtkGenericOpenGLRenderWindow��������ΪQt�����ϵ�RenderWindow
	ui.widget->setRenderWindow(renderWindow);

}

VtkTest::~VtkTest()
{}





