#pragma once

#include <opencv2/core/core_c.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <msclr/marshal_cppstd.h>

#include <iostream>

#include <math.h>

using namespace cv;

Mat img;
int img_height, img_width;


namespace MyopenCV {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  LoadImgGray;
	private: System::Windows::Forms::Button^  LoadImgRGB;
	private: System::Windows::Forms::Button^  Inverse;
	private: System::Windows::Forms::Button^  RGBtoGray;
	private: System::Windows::Forms::Button^  RGB;


	private: System::Windows::Forms::Button^  BinarizeByValue;
	private: System::Windows::Forms::Button^  LowPassFilter;
	private: System::Windows::Forms::Button^  MedianFilter;
	protected:







	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  Sobel;
	private: System::Windows::Forms::Button^  Laplacian;

	private: System::Windows::Forms::Button^  RGBtoHSV;
	private: System::Windows::Forms::Button^  Hog;
	private: System::Windows::Forms::Button^  HistogramEqualization;
	private: System::Windows::Forms::Button^  ContrastStretch;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  Erosion;
	private: System::Windows::Forms::Button^  Dilation;
	private: System::Windows::Forms::Button^  TwoPass;
	private: System::Windows::Forms::Button^  CV_Function;



	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->LoadImgGray = (gcnew System::Windows::Forms::Button());
			this->LoadImgRGB = (gcnew System::Windows::Forms::Button());
			this->Inverse = (gcnew System::Windows::Forms::Button());
			this->RGBtoGray = (gcnew System::Windows::Forms::Button());
			this->RGB = (gcnew System::Windows::Forms::Button());
			this->BinarizeByValue = (gcnew System::Windows::Forms::Button());
			this->LowPassFilter = (gcnew System::Windows::Forms::Button());
			this->MedianFilter = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Sobel = (gcnew System::Windows::Forms::Button());
			this->Laplacian = (gcnew System::Windows::Forms::Button());
			this->RGBtoHSV = (gcnew System::Windows::Forms::Button());
			this->Hog = (gcnew System::Windows::Forms::Button());
			this->HistogramEqualization = (gcnew System::Windows::Forms::Button());
			this->ContrastStretch = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->chart2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->Erosion = (gcnew System::Windows::Forms::Button());
			this->Dilation = (gcnew System::Windows::Forms::Button());
			this->TwoPass = (gcnew System::Windows::Forms::Button());
			this->CV_Function = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->BeginInit();
			this->SuspendLayout();
			// 
			// LoadImgGray
			// 
			this->LoadImgGray->Location = System::Drawing::Point(28, 24);
			this->LoadImgGray->Name = L"LoadImgGray";
			this->LoadImgGray->Size = System::Drawing::Size(102, 32);
			this->LoadImgGray->TabIndex = 0;
			this->LoadImgGray->Text = L"Load Img Gray";
			this->LoadImgGray->UseVisualStyleBackColor = true;
			this->LoadImgGray->Click += gcnew System::EventHandler(this, &MyForm::LoadImgGray_Click);
			// 
			// LoadImgRGB
			// 
			this->LoadImgRGB->Location = System::Drawing::Point(143, 24);
			this->LoadImgRGB->Name = L"LoadImgRGB";
			this->LoadImgRGB->Size = System::Drawing::Size(102, 32);
			this->LoadImgRGB->TabIndex = 1;
			this->LoadImgRGB->Text = L"Load Img RGB";
			this->LoadImgRGB->UseVisualStyleBackColor = true;
			this->LoadImgRGB->Click += gcnew System::EventHandler(this, &MyForm::LoadImgRGB_Click);
			// 
			// Inverse
			// 
			this->Inverse->Location = System::Drawing::Point(28, 71);
			this->Inverse->Name = L"Inverse";
			this->Inverse->Size = System::Drawing::Size(217, 33);
			this->Inverse->TabIndex = 2;
			this->Inverse->Text = L"Day1: Inverse";
			this->Inverse->UseVisualStyleBackColor = true;
			this->Inverse->Click += gcnew System::EventHandler(this, &MyForm::Inverse_Click);
			// 
			// RGBtoGray
			// 
			this->RGBtoGray->Location = System::Drawing::Point(28, 121);
			this->RGBtoGray->Name = L"RGBtoGray";
			this->RGBtoGray->Size = System::Drawing::Size(217, 33);
			this->RGBtoGray->TabIndex = 3;
			this->RGBtoGray->Text = L"Day2: RGB to Gray By 2Darray";
			this->RGBtoGray->UseVisualStyleBackColor = true;
			this->RGBtoGray->Click += gcnew System::EventHandler(this, &MyForm::RGBtoGray_Click);
			// 
			// RGB
			// 
			this->RGB->Location = System::Drawing::Point(28, 169);
			this->RGB->Name = L"RGB";
			this->RGB->Size = System::Drawing::Size(217, 33);
			this->RGB->TabIndex = 4;
			this->RGB->Text = L"Day2: R, G, B";
			this->RGB->UseVisualStyleBackColor = true;
			this->RGB->Click += gcnew System::EventHandler(this, &MyForm::RGB_Click);
			// 
			// BinarizeByValue
			// 
			this->BinarizeByValue->Location = System::Drawing::Point(28, 217);
			this->BinarizeByValue->Name = L"BinarizeByValue";
			this->BinarizeByValue->Size = System::Drawing::Size(102, 33);
			this->BinarizeByValue->TabIndex = 5;
			this->BinarizeByValue->Text = L"Day2: Binarize By Value";
			this->BinarizeByValue->UseVisualStyleBackColor = true;
			this->BinarizeByValue->Click += gcnew System::EventHandler(this, &MyForm::BinarizeByValue_Click);
			// 
			// LowPassFilter
			// 
			this->LowPassFilter->Location = System::Drawing::Point(28, 265);
			this->LowPassFilter->Name = L"LowPassFilter";
			this->LowPassFilter->Size = System::Drawing::Size(217, 33);
			this->LowPassFilter->TabIndex = 6;
			this->LowPassFilter->Text = L"Day3: Low-Pass Filter";
			this->LowPassFilter->UseVisualStyleBackColor = true;
			this->LowPassFilter->Click += gcnew System::EventHandler(this, &MyForm::LowPassFilter_Click);
			// 
			// MedianFilter
			// 
			this->MedianFilter->Location = System::Drawing::Point(28, 313);
			this->MedianFilter->Name = L"MedianFilter";
			this->MedianFilter->Size = System::Drawing::Size(217, 33);
			this->MedianFilter->TabIndex = 7;
			this->MedianFilter->Text = L"Day3: Median Filter";
			this->MedianFilter->UseVisualStyleBackColor = true;
			this->MedianFilter->Click += gcnew System::EventHandler(this, &MyForm::MedianFilter_Click);
			// 
			// chart1
			// 
			chartArea1->BorderWidth = 0;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(615, 24);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->IsVisibleInLegend = false;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			series2->ChartArea = L"ChartArea1";
			series2->IsVisibleInLegend = false;
			series2->Legend = L"Legend1";
			series2->Name = L"Series2";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(558, 322);
			this->chart1->TabIndex = 8;
			this->chart1->Text = L"chart1";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(282, 24);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(302, 322);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"save";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(143, 224);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(101, 22);
			this->textBox1->TabIndex = 10;
			// 
			// Sobel
			// 
			this->Sobel->Location = System::Drawing::Point(27, 362);
			this->Sobel->Name = L"Sobel";
			this->Sobel->Size = System::Drawing::Size(217, 33);
			this->Sobel->TabIndex = 11;
			this->Sobel->Text = L"Day4: Sobel";
			this->Sobel->UseVisualStyleBackColor = true;
			this->Sobel->Click += gcnew System::EventHandler(this, &MyForm::Sobel_Click);
			// 
			// Laplacian
			// 
			this->Laplacian->Location = System::Drawing::Point(27, 410);
			this->Laplacian->Name = L"Laplacian";
			this->Laplacian->Size = System::Drawing::Size(217, 33);
			this->Laplacian->TabIndex = 12;
			this->Laplacian->Text = L"\?\? Day4: Laplacian";
			this->Laplacian->UseVisualStyleBackColor = true;
			this->Laplacian->Click += gcnew System::EventHandler(this, &MyForm::Laplacian_Click);
			// 
			// RGBtoHSV
			// 
			this->RGBtoHSV->Location = System::Drawing::Point(28, 458);
			this->RGBtoHSV->Name = L"RGBtoHSV";
			this->RGBtoHSV->Size = System::Drawing::Size(217, 33);
			this->RGBtoHSV->TabIndex = 13;
			this->RGBtoHSV->Text = L"Day4: RGB to HSV";
			this->RGBtoHSV->UseVisualStyleBackColor = true;
			this->RGBtoHSV->Click += gcnew System::EventHandler(this, &MyForm::RGBtoHSV_Click);
			// 
			// Hog
			// 
			this->Hog->Location = System::Drawing::Point(283, 458);
			this->Hog->Name = L"Hog";
			this->Hog->Size = System::Drawing::Size(217, 33);
			this->Hog->TabIndex = 16;
			this->Hog->Text = L"Day5: 8x8x9 Hog";
			this->Hog->UseVisualStyleBackColor = true;
			this->Hog->Click += gcnew System::EventHandler(this, &MyForm::Hog_Click);
			// 
			// HistogramEqualization
			// 
			this->HistogramEqualization->Location = System::Drawing::Point(282, 410);
			this->HistogramEqualization->Name = L"HistogramEqualization";
			this->HistogramEqualization->Size = System::Drawing::Size(217, 33);
			this->HistogramEqualization->TabIndex = 15;
			this->HistogramEqualization->Text = L"Day5: Histogram Equalization";
			this->HistogramEqualization->UseVisualStyleBackColor = true;
			this->HistogramEqualization->Click += gcnew System::EventHandler(this, &MyForm::HistogramEqualization_Click);
			// 
			// ContrastStretch
			// 
			this->ContrastStretch->Location = System::Drawing::Point(282, 362);
			this->ContrastStretch->Name = L"ContrastStretch";
			this->ContrastStretch->Size = System::Drawing::Size(217, 33);
			this->ContrastStretch->TabIndex = 14;
			this->ContrastStretch->Text = L"Day5: Contrast Stretch";
			this->ContrastStretch->UseVisualStyleBackColor = true;
			this->ContrastStretch->Click += gcnew System::EventHandler(this, &MyForm::ContrastStretch_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(534, 362);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(217, 33);
			this->button1->TabIndex = 17;
			this->button1->Text = L"xDay5:";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// chart2
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart2->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart2->Legends->Add(legend2);
			this->chart2->Location = System::Drawing::Point(28, 515);
			this->chart2->Name = L"chart2";
			series3->ChartArea = L"ChartArea1";
			series3->CustomProperties = L"PointWidth=1";
			series3->IsVisibleInLegend = false;
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chart2->Series->Add(series3);
			this->chart2->Size = System::Drawing::Size(1145, 241);
			this->chart2->TabIndex = 18;
			this->chart2->Text = L"chart2";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Consolas", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(1202, 24);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(343, 732);
			this->richTextBox1->TabIndex = 20;
			this->richTextBox1->Text = L"";
			// 
			// Erosion
			// 
			this->Erosion->Location = System::Drawing::Point(535, 458);
			this->Erosion->Name = L"Erosion";
			this->Erosion->Size = System::Drawing::Size(217, 33);
			this->Erosion->TabIndex = 22;
			this->Erosion->Text = L"Day6: Erosion";
			this->Erosion->UseVisualStyleBackColor = true;
			this->Erosion->Click += gcnew System::EventHandler(this, &MyForm::Erosion_Click);
			// 
			// Dilation
			// 
			this->Dilation->Location = System::Drawing::Point(534, 410);
			this->Dilation->Name = L"Dilation";
			this->Dilation->Size = System::Drawing::Size(217, 33);
			this->Dilation->TabIndex = 21;
			this->Dilation->Text = L"Day6: Dilation";
			this->Dilation->UseVisualStyleBackColor = true;
			this->Dilation->Click += gcnew System::EventHandler(this, &MyForm::Dilation_Click);
			// 
			// TwoPass
			// 
			this->TwoPass->Location = System::Drawing::Point(785, 362);
			this->TwoPass->Name = L"TwoPass";
			this->TwoPass->Size = System::Drawing::Size(217, 33);
			this->TwoPass->TabIndex = 23;
			this->TwoPass->Text = L"Day6: Two-Pass Algo";
			this->TwoPass->UseVisualStyleBackColor = true;
			this->TwoPass->Click += gcnew System::EventHandler(this, &MyForm::TwoPass_Click);
			// 
			// CV_Function
			// 
			this->CV_Function->Location = System::Drawing::Point(785, 410);
			this->CV_Function->Name = L"CV_Function";
			this->CV_Function->Size = System::Drawing::Size(217, 33);
			this->CV_Function->TabIndex = 24;
			this->CV_Function->Text = L"Day7: CV_Function";
			this->CV_Function->UseVisualStyleBackColor = true;
			this->CV_Function->Click += gcnew System::EventHandler(this, &MyForm::CV_Function_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1572, 772);
			this->Controls->Add(this->CV_Function);
			this->Controls->Add(this->TwoPass);
			this->Controls->Add(this->Erosion);
			this->Controls->Add(this->Dilation);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->chart2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Hog);
			this->Controls->Add(this->HistogramEqualization);
			this->Controls->Add(this->ContrastStretch);
			this->Controls->Add(this->RGBtoHSV);
			this->Controls->Add(this->Laplacian);
			this->Controls->Add(this->Sobel);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->MedianFilter);
			this->Controls->Add(this->LowPassFilter);
			this->Controls->Add(this->BinarizeByValue);
			this->Controls->Add(this->RGB);
			this->Controls->Add(this->RGBtoGray);
			this->Controls->Add(this->Inverse);
			this->Controls->Add(this->LoadImgRGB);
			this->Controls->Add(this->LoadImgGray);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void showChart(int *inputArray, int *outputArray) {
		chart1->Series["Series1"]->CustomProperties = L"PointWidth = 1";
		chart1->Series["Series2"]->CustomProperties = L"PointWidth = 1";
		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series2"]->Points->Clear();

		for (int i = 0; i < 256; i++) {
			chart1->Series["Series1"]->Points->AddXY(i + 1, inputArray[i]);
			chart1->Series["Series2"]->Points->AddXY(i + 1, outputArray[i]);
		}
	}

	private: System::Void LoadImgGray_Click(System::Object^  sender, System::EventArgs^  e) {

		//Load Image by gray
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Load(openFileDialog1->FileName);

			img = imread(msclr::interop::marshal_as<std::string>(openFileDialog1->FileName), CV_LOAD_IMAGE_GRAYSCALE);
			img_height = img.rows;
			img_width = img.cols;

			imshow("hello", img);
		}
		else {
			return;
		}

	}


	private: System::Void LoadImgRGB_Click(System::Object^  sender, System::EventArgs^  e) {
		//Load Image by gray
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			pictureBox1->Load(openFileDialog1->FileName);

			img = imread(msclr::interop::marshal_as<std::string>(openFileDialog1->FileName), CV_LOAD_IMAGE_COLOR);
			img_height = img.rows;
			img_width = img.cols;

			imshow("hello", img);
		}
		else {
			return;
		}
	}



	private: System::Void Inverse_Click(System::Object^  sender, System::EventArgs^  e) {
		//Inverse Image
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0, 0, 0));

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				output_img.at<uchar>(i, j) = 255 - img.at<uchar>(i, j);
			}
		}

		imshow("inverse", output_img);

	}


	private: System::Void ContrastStretch_Click(System::Object^  sender, System::EventArgs^  e) {

		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0, 0, 0));
		int
			input_gray[256] = { 0 },
			output_gray[256] = { 0 };

		int cmax = -1,
			cmin = 256;

		//find cmax, cmin
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);

				cmax = max(cmax, value);
				cmin = min(cmin, value);
			
				input_gray[value]++;
			}
		}

		//Contrast Stretch
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int 
					value = img.at<uchar>(i, j),
					output_value;
				
				
				if (value >= cmax)		output_value = 255;
				else if (value <= cmin)	output_value = 0;
				else					output_value = 255 * (value - cmin) / (cmax - cmin);

				output_img.at<uchar>(i, j) = output_value;
				output_gray[output_value]++;
			}
		}
		imshow("Contrast Stretch", output_img);
		showChart(input_gray, output_gray);
		
	}
	private: System::Void HistogramEqualization_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0, 0, 0));
		int
			input_gray[256] = { 0 },
			output_gray[256] = { 0 };
		float
			pdf[256] = { 0 },
			cdf[256] = { 0 };
		
		//Analysis Image value
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);
				input_gray[value]++;
			}
		}

		//Calculate pdf, cdf, output_value
		for (int i = 0; i < 256; i++) {

			float pdf1 = input_gray[i]/img_height;
			pdf[i] = pdf1/img_width;
			
			if (i == 0) cdf[i] = pdf[i];
			else cdf[i] = cdf[i - 1] + pdf[i];

			output_gray[i] = 255 * cdf[i];
		}

		//Change to output_img
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);
				output_img.at<uchar>(i, j) = output_gray[value];
			}
		}
		imshow("Histogram Equalization", output_img);
		showChart(input_gray, output_gray);
	}
	private: System::Void Hog_Click(System::Object^  sender, System::EventArgs^  e) {

		//segment 8x8 cells
		Mat cell[8][8];
		int cell_height = img_height / 8,
			cell_width = img_width / 8;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cell[i][j] = Mat(cell_height, cell_width, CV_8UC1, Scalar(0, 0, 0));

				for (int h = 0; h < cell_height; h++) {
					for (int w = 0; w < cell_width; w++) {
						cell[i][j].at<uchar>(h, w) = img.at<uchar>(h + i*cell_height, w + j*cell_width);
					}
				}
			}
		}

		richTextBox1->Text = "";
		//calculate every cells
		float **hist = new float*[8 * 8];

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				hist[i * 8 + j] = HogByCell(cell[i][j]);
			}	
		}
		

		//show chart
		chart2->Series["Series1"]->Points->Clear();
	
		for (int cell = 0; cell < 8 * 8; cell++) {
			for (int i = 0; i < 9; i++) {
				chart2->Series["Series1"]->Points->AddXY(cell*9 + i + 1, hist[cell][i]);
			}
		}
	}

	float* HogByCell(Mat cell) {
		int height = cell.rows,
			width = cell.cols;

		int
			**img_array = new int*[height],
			**grad_x = new int*[height],
			**grad_y = new int*[height],
			**Gx = new int*[height],
			**Th = new int*[height];

		for (int i = 0; i < height; i++) {
			img_array[i] = new int[width];
			grad_x[i] = new int[width];
			grad_y[i] = new int[width];
			Gx[i] = new int[width];
			Th[i] = new int[width];
		}

		//put image into array
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				img_array[i][j] = cell.at<uchar>(i, j);
				grad_x[i][j] = { 0 };
				grad_y[i][j] = { 0 };
				Gx[i][j] = { 0 };
				Th[i][j] = { 0 };
			}
		}

		//calculate gradient_x, gradient_y, Gx, Th
		for (int i = 1; i < height - 1; i++) {
			for (int j = 1; j < width - 1; j++) {
				grad_x[i][j] = img_array[i + 1][j] - img_array[i - 1][j];
				grad_y[i][j] = img_array[i][j + 1] - img_array[i][j - 1];

				Gx[i][j] = sqrt(pow(grad_x[i][j], 2) + pow(grad_y[i][j], 2));

				float radians, angle;
				if (grad_x[i][j] != 0) {
					radians = atan((float)grad_y[i][j] / (float)grad_x[i][j]);
					angle = radians * (180.0 / Math::PI);
				}
				else {
					angle = 90;
				}

				Th[i][j] = angle + 90;
			}
		}
		//show log
		System::String^ myString = System::String::Format("grad_x:{0,-4},  grad_y:{1,-4},  Gx:{2,-4},  Th:{3,-4}\n"
			, grad_x[15][5], grad_y[15][5], Gx[15][5], Th[15][5]);
		richTextBox1->Text += myString;

		//do statistic all degree
		float *hist = new float[9];
		for (int i = 0; i < 9; i++) {
			hist[i] = 0;
		}

		for (int i = 1; i < height - 1; i++) {
			for (int j = 1; j < width - 1; j++) {
				if(Th[i][j]>= 0 && Th[i][j] < 20 || Th[i][j] == 180)	hist[0] += Gx[i][j];
				else if(Th[i][j] >= 20 && Th[i][j] < 40)				hist[1] += Gx[i][j];
				else if (Th[i][j] >= 40 && Th[i][j] < 60)				hist[2] += Gx[i][j];
				else if (Th[i][j] >= 60 && Th[i][j] < 80)				hist[3] += Gx[i][j];
				else if (Th[i][j] >= 80 && Th[i][j] < 100)				hist[4] += Gx[i][j];
				else if (Th[i][j] >= 100 && Th[i][j] < 120)				hist[5] += Gx[i][j];
				else if (Th[i][j] >= 120 && Th[i][j] < 140)				hist[6] += Gx[i][j];
				else if (Th[i][j] >= 140 && Th[i][j] < 160)				hist[7] += Gx[i][j];
				else if (Th[i][j] >= 160 && Th[i][j] < 0)				hist[8] += Gx[i][j];
			}
		}

		//normalization
		int cmax = hist[0],
			cmin = hist[0];
		for (int i = 0; i < 9; i++) {
			cmax = max(cmax, hist[i]);
			cmin = min(cmin, hist[i]);
		}
		for (int i = 0; i < 9; i++) {
			hist[i] = (hist[i] - cmin) / (cmax - cmin);
		}

		return hist;
	}



	private: System::Void BinarizeByValue_Click(System::Object^  sender, System::EventArgs^  e) {
		int threshold = Convert::ToInt32(textBox1->Text);
		int 
			input_gray[256] = { 0 },
			output_gray[256] = { 0 };

		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0, 0, 0));

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);

				input_gray[value]++;

				if (value > threshold)	output_img.at<uchar>(i, j) = 255;
				else					output_img.at<uchar>(i, j) = 0;
			}
		}
		output_gray[threshold] = input_gray[threshold];
		imshow("binarize", output_img);
		showChart(input_gray, output_gray);
	}


	private: System::Void Dilation_Click(System::Object^  sender, System::EventArgs^  e) {
		
		int dilation_filter[3][3] = {
			{ 0, 1, 0 },
			{ 1, 1, 1 },
			{ 0, 1, 0 }
		};

		//check binarize
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);

				if (value > 127)	img.at<uchar>(i, j) = 255;
				else				img.at<uchar>(i, j) = 0;
			}
		}

		//image to 2Darray
		int **img_array = new int*[img_height];
		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do dilation
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
						
				if (doFilter(i, j, img_array, dilation_filter, 5) != 0)	
						img.at<uchar>(i, j) = 255;
				else	img.at<uchar>(i, j) = 0;
			}
		}

		imshow("Dilation", img);
	}

	private: System::Void Erosion_Click(System::Object^  sender, System::EventArgs^  e) {
		int erosion_filter[3][3] = {
			{ 0, 1, 0 },
			{ 1, 1, 1 },
			{ 0, 1, 0 }
		};

		//check binarize
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);

				if (value > 127)	img.at<uchar>(i, j) = 255;
				else				img.at<uchar>(i, j) = 0;
			}
		}

		//image to 2Darray
		int **img_array = new int*[img_height];
		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do erosion
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {

				if (doFilter(i, j, img_array, erosion_filter, 5) == 255)
					img.at<uchar>(i, j) = 255;
				else	img.at<uchar>(i, j) = 0;
			}
		}

		imshow("Erosion", img);
	}



	int doFilter(int i, int j, int **Array, int filter[3][3], int filter_weight) {
		int sum = 0;
		sum += Array[i - 1][j - 1] * filter[0][0];
		sum += Array[i - 1][j] * filter[0][1];
		sum += Array[i - 1][j + 1] * filter[0][2];
		sum += Array[i][j + 1] * filter[1][2];
		sum += Array[i + 1][j + 1] * filter[2][2];
		sum += Array[i + 1][j] * filter[2][1];
		sum += Array[i + 1][j - 1] * filter[2][0];
		sum += Array[i][j - 1] * filter[1][0];
		sum += Array[i][j] * filter[1][1];

		sum /= filter_weight;

		return sum;
	}

	private: System::Void TwoPass_Click(System::Object^  sender, System::EventArgs^  e) {
		//parent[ label_ID ] = parent_ID; 
		int parent[255] = { 0 };
		int cur_label_ID = 5;


		//check binarize
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = img.at<uchar>(i, j);

				if (value > 127)	img.at<uchar>(i, j) = 255;
				else				img.at<uchar>(i, j) = 0;
			}
		}


		//build setting_array
		int **setting_array = new int*[img_height],
			**img_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			setting_array[i] = new int[img_width];
			img_array[i] = new int[img_width];
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				setting_array[i][j] = 0;
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do two-pass
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				int value = img.at<uchar>(i, j);

				//if no value
				if (value == 0)	setting_array[i][j] = 0;
				else {
					//case1: if neighbor is empty
					if (isNeighborEmpty(i, j, setting_array)) {
						setting_array[i][j] = cur_label_ID;
						parent[cur_label_ID] = 0; //root
						cur_label_ID++;
					}

					//case2: rebuild tree
					else {
						int *neighbor = findAllNeighbor(i, j, setting_array);

						//find min label
						int min_label = 99;
						for (int i = 0; i < 8; i++) {
							if (neighbor[i] != 0) 
								min_label = min(min_label, neighbor[i]);
						}
						setting_array[i][j] = min_label;

						//change parent
						for (int i = 0; i < 8; i++) {
							if (neighbor[i] != 0) {
								int neighbor_ancestor = findAncestor(neighbor[i], parent),
									min_label_ancestor = findAncestor(min_label, parent);

								if (neighbor_ancestor != min_label_ancestor) {
									parent[neighbor_ancestor] = min_label_ancestor;
								}
							}

						}
					}
				}


			}
		}

		//show text
		richTextBox1->Text = "";
		 
		for(int i = 5; i < cur_label_ID; i++){
			System::String^ myString = System::String::Format("label: {0,3}, parent:{1,3}\n", i, parent[i]);
			richTextBox1->Text += myString;
		}

		richTextBox1->Text += "\n\n";


		//change value to ancestor
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0));

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				if(setting_array[i][j] != 0)
					setting_array[i][j] = findAncestor(setting_array[i][j], parent);
				
				output_img.at<uchar>(i, j) = setting_array[i][j]*25;
			}
		}
		namedWindow("XDDD", WINDOW_NORMAL);
		resizeWindow("XDDD", 500, 500);
		imshow("XDDD", output_img);

		//show text
		/*
		richTextBox2->Text = "";
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				int value = output_img.at<uchar>(i, j);
				System::String^ myString = System::String::Format("{0,2}", value);
				richTextBox2->Text += myString;
			}
			richTextBox2->Text += "\n";
		}
		*/
	}

	int findAncestor(int index, int parent[]) {
		
		int temp = index;
		while (parent[temp] != 0){
			temp = parent[temp];
		}

		return temp;
	}


	int* findAllNeighbor(int i, int j, int **input_array) {
		int *neighbor = new int[8];
		
		neighbor[0] = input_array[i - 1][j - 1];
		neighbor[1] = input_array[i - 1][j    ];
		neighbor[2] = input_array[i - 1][j + 1];
		neighbor[3] = input_array[i    ][j + 1];
		neighbor[4] = input_array[i + 1][j + 1];
		neighbor[5] = input_array[i + 1][j    ];
		neighbor[6] = input_array[i + 1][j - 1];
		neighbor[7] = input_array[i    ][j - 1];
		 
		return neighbor;
	}

	bool isNeighborEmpty(int i, int j, int **input_array) {
		if(
			input_array[i - 1][j - 1] == 0 &&
			input_array[i - 1][j    ] == 0 &&
			input_array[i - 1][j + 1] == 0 &&
			input_array[i    ][j + 1] == 0 &&
			input_array[i + 1][j + 1] == 0 &&
			input_array[i + 1][j    ] == 0 &&
			input_array[i + 1][j - 1] == 0 &&
			input_array[i    ][j - 1] == 0 &&
			input_array[i    ][j    ] == 0
		)	return true;
		else 
			return false;
	}

	private: System::Void CV_Function_Click(System::Object^  sender, System::EventArgs^  e) {
		Mat filter2D_img, sobel_img, dilate_img, erosion_img;
		
		//filter2D
		Mat lowPass_filter(3, 3, CV_32F, Scalar(0));
		lowPass_filter.at<float>(0, 0) = 1.0 / 9.0;
		lowPass_filter.at<float>(0, 1) = 1.0 / 9.0;
		lowPass_filter.at<float>(0, 2) = 1.0 / 9.0;
		lowPass_filter.at<float>(1, 2) = 1.0 / 9.0;
		lowPass_filter.at<float>(2, 2) = 1.0 / 9.0;
		lowPass_filter.at<float>(2, 1) = 1.0 / 9.0;
		lowPass_filter.at<float>(2, 0) = 1.0 / 9.0;
		lowPass_filter.at<float>(1, 0) = 1.0 / 9.0;
		lowPass_filter.at<float>(1, 1) = 1.0 / 9.0;

		cv::filter2D(img, filter2D_img, img.depth(), lowPass_filter);
		imshow("XDD", filter2D_img);


		//Sobel
		cv::Sobel(img, sobel_img, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT);
		cv::convertScaleAbs(sobel_img, sobel_img);
		cv::Sobel(img, sobel_img, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
		cv::convertScaleAbs(sobel_img, sobel_img);
		imshow("XDD1", sobel_img);


		//Dilation
		Mat dilate_erosion_filter(3, 3, CV_8UC1, Scalar(0));
		dilate_erosion_filter.at<uchar>(0, 0) = 0;
		dilate_erosion_filter.at<uchar>(0, 1) = 1;
		dilate_erosion_filter.at<uchar>(0, 2) = 0;
		dilate_erosion_filter.at<uchar>(1, 2) = 1;
		dilate_erosion_filter.at<uchar>(2, 2) = 0;
		dilate_erosion_filter.at<uchar>(2, 1) = 1;
		dilate_erosion_filter.at<uchar>(2, 0) = 0;
		dilate_erosion_filter.at<uchar>(1, 0) = 1;
		dilate_erosion_filter.at<uchar>(1, 1) = 1;

		cv::dilate(img, dilate_img, dilate_erosion_filter);
		imshow("XDD2", dilate_img);


		//Erosion
		cv::erode(img, erosion_img, dilate_erosion_filter);
		imshow("XDD3", erosion_img);

	}
	private: System::Void RGBtoGray_Click(System::Object^  sender, System::EventArgs^  e) {
		
		//build 2Darray
		uchar 
			**R_array = new uchar*[img_height],
			**G_array = new uchar*[img_height],
			**B_array = new uchar*[img_height];
		
		for (int i = 0; i < img_height; i++) {
			R_array[i] = new uchar[img_width];
			G_array[i] = new uchar[img_width];
			B_array[i] = new uchar[img_width];
		}


		//set image to 2Darray
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				B_array[i][j] = img.at<Vec3b>(i, j)[0];
				G_array[i][j] = img.at<Vec3b>(i, j)[1];
				R_array[i][j] = img.at<Vec3b>(i, j)[2];
			}
		}


		//calculate gray value to new image
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0));
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				float gray
					= 0.299 * R_array[i][j]
					+ 0.587 * G_array[i][j]
					+ 0.114 * B_array[i][j];

				output_img.at<uchar>(i, j) = (uchar)gray;
			}
		}
		imshow("RGB to Gray By 2Darray", output_img);
	}


	private: System::Void RGB_Click(System::Object^  sender, System::EventArgs^  e) {
		//build 2Darray
		uchar
			**R_array = new uchar*[img_height],
			**G_array = new uchar*[img_height],
			**B_array = new uchar*[img_height];

		for (int i = 0; i < img_height; i++) {
			R_array[i] = new uchar[img_width];
			G_array[i] = new uchar[img_width];
			B_array[i] = new uchar[img_width];
		}


		//set image to 2Darray
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				B_array[i][j] = img.at<Vec3b>(i, j)[0];
				G_array[i][j] = img.at<Vec3b>(i, j)[1];
				R_array[i][j] = img.at<Vec3b>(i, j)[2];
			}
		}

		//Set value to R, G, B image
		Mat R_img(img_height, img_width, CV_8UC3, Scalar(0));
		Mat G_img(img_height, img_width, CV_8UC3, Scalar(0));
		Mat B_img(img_height, img_width, CV_8UC3, Scalar(0));
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				R_img.at<Vec3b>(i, j)[0] = 0;
				R_img.at<Vec3b>(i, j)[1] = 0;
				R_img.at<Vec3b>(i, j)[2] = R_array[i][j];

				G_img.at<Vec3b>(i, j)[0] = 0;
				G_img.at<Vec3b>(i, j)[1] = G_array[i][j];
				G_img.at<Vec3b>(i, j)[2] = 0;

				B_img.at<Vec3b>(i, j)[0] = B_array[i][j];
				B_img.at<Vec3b>(i, j)[1] = 0;
				B_img.at<Vec3b>(i, j)[2] = 0;
			}
		}
		imshow("R Image", R_img);
		imshow("G Image", G_img);
		imshow("B Image", B_img);
	}



	private: System::Void LowPassFilter_Click(System::Object^  sender, System::EventArgs^  e) {
		int lowPass_filter[3][3] = {
			{ 1, 2, 1 },
			{ 2, 4, 2 },
			{ 1, 2, 1 }
		},
			lowPass_weight = 16;

		int **img_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
		}

		//set image to 2Darray
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do filter
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				img.at<uchar>(i,j) = doFilter(i, j, img_array, lowPass_filter, lowPass_weight);
			}
		}
		imshow("Low-Pass Filter", img);
	}


	private: System::Void MedianFilter_Click(System::Object^  sender, System::EventArgs^  e) {
		int lowPass_filter[3][3] = {
			{ 1, 2, 1 },
			{ 2, 4, 2 },
			{ 1, 2, 1 }
		},
			lowPass_weight = 16;

		int **img_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
		}

		//set image to 2Darray
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do filter
		int sorting[9] = { 0 };

		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				sorting[0] = img_array[i - 1][j - 1];
				sorting[1] = img_array[i - 1][j    ];
				sorting[2] = img_array[i - 1][j + 1];
				sorting[3] = img_array[i    ][j + 1];
				sorting[4] = img_array[i + 1][j + 1];
				sorting[5] = img_array[i + 1][j    ];
				sorting[6] = img_array[i + 1][j - 1];
				sorting[7] = img_array[i    ][j - 1];
				sorting[8] = img_array[i    ][j    ];

				std::sort(sorting, sorting + 9);

				img.at<uchar>(i, j) = sorting[4];
			}
		}
		imshow("Median Filter", img);
	}
	private: System::Void Sobel_Click(System::Object^  sender, System::EventArgs^  e) {
		int sobel_gx_filter[3][3] = {
			{ -1, 0, 1 },
			{ -2, 0, 2 },
			{ -1, 0, 1 }
		};

		int sobel_gy_filter[3][3] = {
			{ -1, -2, -1 },
			{  0,  0,  0 },
			{  1,  2,  1 }
		};

		//build img_array
		int **img_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
			}
		}

		//do Sobel
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0));

		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				int gx = doFilter(i, j, img_array, sobel_gx_filter, 1),
					gy = doFilter(i, j, img_array, sobel_gy_filter, 1);
				float G_value;

				G_value = sqrt(pow(gx, 2) + pow(gy, 2));

				output_img.at<uchar>(i, j) = G_value;
			}
		}

		imshow("Sobel", output_img);
	}


	private: System::Void Laplacian_Click(System::Object^  sender, System::EventArgs^  e) {
		int laplacian_filter[3][3] = {
			{ 0,  1,  0 },
			{ 1, -4,  1 },
			{ 0,  1,  0 }
		};


		//build img_array
		int **img_array = new int*[img_height],
			**output_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			img_array[i] = new int[img_width];
			output_array[i] = new int[img_width];
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				img_array[i][j] = img.at<uchar>(i, j);
				output_array[i][j] = 0;
			}
		}

		//do filter
		Mat output_img(img_height, img_width, CV_8UC1, Scalar(0));
		
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				output_array[i][j] = doFilter(i, j, img_array, laplacian_filter, 1);
			}
		}

		//show img
		int cmin = 256;
		for (int i = 1; i < img_height - 1; i++) {
			for (int j = 1; j < img_width - 1; j++) {
				cmin = min(cmin, output_array[i][j]);
			}
		}

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				output_img.at<uchar>(i, j) = output_array[i][j] + abs(cmin);
			}
		}

		imshow("Laplacian Filter", output_img);
	}


	private: System::Void RGBtoHSV_Click(System::Object^  sender, System::EventArgs^  e) {
		//build 2Darray
		uchar
			**R_array = new uchar*[img_height],
			**G_array = new uchar*[img_height],
			**B_array = new uchar*[img_height];

		int		**H_array = new int*[img_height];
		float	**S_array = new float*[img_height];
		int		**V_array = new int*[img_height];

		for (int i = 0; i < img_height; i++) {
			R_array[i] = new uchar[img_width];
			G_array[i] = new uchar[img_width];
			B_array[i] = new uchar[img_width];

			H_array[i] = new int[img_width];
			S_array[i] = new float[img_width];
			V_array[i] = new int[img_width];
		}


		//set image to 2Darray
		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				B_array[i][j] = img.at<Vec3b>(i, j)[0];
				G_array[i][j] = img.at<Vec3b>(i, j)[1];
				R_array[i][j] = img.at<Vec3b>(i, j)[2];

				H_array[i][j] = 0;
				S_array[i][j] = 0;
				V_array[i][j] = 0;
			}
		}


		//show output image
		Mat output_img(img_height, img_width, CV_8UC3, Scalar(0));
		richTextBox1->Text = "";

		for (int i = 0; i < img_height; i++) {
			for (int j = 0; j < img_width; j++) {
				H_array[i][j] = find_H(R_array[i][j], G_array[i][j], B_array[i][j]);
				S_array[i][j] = find_S(R_array[i][j], G_array[i][j], B_array[i][j]);
				V_array[i][j] = find_V(R_array[i][j], G_array[i][j], B_array[i][j]);

				output_img.at<Vec3b>(i, j)[0] = (uchar) H_array[i][j];
				output_img.at<Vec3b>(i, j)[1] = (uchar) S_array[i][j];
				output_img.at<Vec3b>(i, j)[2] = (uchar) V_array[i][j];
			}

			//show log
			System::String^ myString = System::String::Format("H:{0,3}, S:{1:F3}, V:{2,-3},   R:{3,3}, G:{4,3}, B:{5,3}\n"
				, H_array[i][5], S_array[i][5], V_array[i][5], R_array[i][5], G_array[i][5], B_array[i][5]);
			richTextBox1->Text += myString;
		}

		imshow("RGB to HSV", output_img);
	}

	int find_H(int R, int G, int B) {
		int cmax = max(max(R, G), B),
			cmin = min(min(R, G), B);

		if (cmax == cmin)				return 0;
		else if (cmax == R && G >= B)	return 60 * (float)(G - B) / (float)(cmax - cmin) + 0;
		else if(cmax == R && G < B)		return 60 * (float)(G - B) / (float)(cmax - cmin) + 360;
		else if(cmax == G)				return 60 * (float)(B - R) / (float)(cmax - cmin) + 120;
		else if(cmax == B)				return 60 * (float)(R - G) / (float)(cmax - cmin) + 240;
		else							return -1;
	}

	float find_S(int R, int G, int B) {
		int cmax = max(max(R, G), B),
			cmin = min(min(R, G), B);

		if (cmax == 0)	return 0;
		else			return 1 - ((float) cmin / (float) cmax);
	}

	int find_V(int R, int G, int B) {
		return max(max(R, G), B);
	}
};
}
