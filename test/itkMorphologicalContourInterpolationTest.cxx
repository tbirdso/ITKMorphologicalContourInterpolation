/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"
#include "itkMorphologicalContourInterpolator.h"

int itkMorphologicalContourInterpolationTest( int argc, char* argv[] )
{
  if( argc < 3 )
    {
    std::cerr << "Usage: " << argv[0];
    std::cerr << " inputImage outputImage";
    std::cerr << std::endl;
    return EXIT_FAILURE;
    }
  const char * inputImageFileName = argv[1];
  const char * outputImageFileName = argv[2];

  typedef signed short PixelType;
  const unsigned int Dimension = 3;
  typedef itk::Image< PixelType, Dimension > ImageType;

  typedef itk::ImageFileReader < ImageType > ReaderType;
  ReaderType::Pointer reader     = ReaderType::New();
  reader->SetFileName( inputImageFileName );

  typedef itk::MorphologicalContourInterpolator<ImageType> mciType;
  mciType::Pointer mci = mciType::New();
  mci->SetInput(reader->GetOutput());
  mci->SetLabel(0);

  typedef itk::ImageFileWriter< ImageType > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName( outputImageFileName );
  writer->SetInput(mci->GetOutput());
  writer->SetUseCompression(true);

  try
    {
    writer->Update();
    }
  catch( itk::ExceptionObject & error )
    {
    std::cerr << "Error: " << error << std::endl;
    return EXIT_FAILURE;
    }

  return EXIT_SUCCESS;
}
