#pragma once

#include <memory>

// mapnik
#include <mapnik\layer.hpp>

namespace NETMapnik
{
	typedef std::shared_ptr<mapnik::layer> layer_ptr;

	//Forward Declare
	ref class Datasource;

	public ref class Layer
	{
	public:
		Layer(System::String^ name);
		Layer(System::String^ name, System::String^ srs);
		~Layer();

		property System::String^ Name
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::String^ SRS
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::Boolean CacheFeatures
		{
			System::Boolean get();
			void set(System::Boolean value);
		}

		property System::String^ GroupBy
		{
			System::String^ get();
			void set(System::String^ value);
		}

		property System::Collections::Generic::IEnumerable<System::String^>^ Styles
		{
			System::Collections::Generic::IEnumerable<System::String^>^ get();
			void set(System::Collections::Generic::IEnumerable<System::String^>^ value);
		}

		property Datasource^ Datasource
		{
			NETMapnik::Datasource^ get();
			void set(NETMapnik::Datasource^ value);
		}

		System::Collections::Generic::IDictionary<System::String^, System::Object^>^ Describe();

	internal:
		Layer(mapnik::layer const &layer);
		layer_ptr NativeObject();

	private:
		layer_ptr *_layer;
	};
}
