#pragma once
#include <memory>
#include <stdexcept>

template<typename T>
class MyOptional
{
public:
	MyOptional() noexcept;
	MyOptional(const T& value) noexcept;
	MyOptional(const MyOptional<T>& other) noexcept;
	~MyOptional() = default;
	void emplace(const T& value) noexcept;
	void reset() noexcept;
	T& value() const;
	bool has_value() const noexcept;
	T& operator*() noexcept;
	T value_or(const T& other) const noexcept;
	MyOptional<T>& operator=(MyOptional<T>&& other) noexcept;
	MyOptional<T>& operator=(const MyOptional<T>& other) noexcept;
	

private:
	std::unique_ptr<T> m_value;
};

//---------------------------------------------------------------------------

template<typename T>
inline MyOptional<T>::MyOptional() noexcept : m_value(nullptr)
{

}

//---------------------------------------------------------------------------

template<typename T>
inline MyOptional<T>::MyOptional(const T& value) noexcept
{
	m_value = std::make_unique<T>(value);
}

//---------------------------------------------------------------------------

template<typename T>
inline MyOptional<T>::MyOptional(const MyOptional<T>& other) noexcept
{
	if (other.has_value()) 
	{
		m_value = std::make_unique<T>(other.value());
	}
}

//---------------------------------------------------------------------------

template<typename T>
inline void MyOptional<T>::emplace(const T& value) noexcept
{
	m_value = std::make_unique<T>(value);
}

//---------------------------------------------------------------------------

template<typename T>
inline void MyOptional<T>::reset() noexcept
{
	m_value.reset();
}

//---------------------------------------------------------------------------

template<typename T>
inline T& MyOptional<T>::value() const
{
	if (!m_value)
	{
		throw std::runtime_error("MyOptional does not have a value!");
	}

	return *m_value;
}

//---------------------------------------------------------------------------

template<typename T>
inline bool MyOptional<T>::has_value() const noexcept
{
	return m_value != nullptr;
}

//---------------------------------------------------------------------------

template<typename T>
inline T& MyOptional<T>::operator*() noexcept
{
	return *m_value;
}

//---------------------------------------------------------------------------

template<typename T>
inline T MyOptional<T>::value_or(const T& other) const noexcept
{
	return m_value ? *m_value : other;
}

template<typename T>
inline MyOptional<T>& MyOptional<T>::operator=(MyOptional<T>&& other) noexcept
{
	if (this != &other) 
	{
		m_value = std::move(other.m_value);
		other.reset();
	}
	return *this;
}

template<typename T>
inline MyOptional<T>& MyOptional<T>::operator=(const MyOptional<T>& other) noexcept
{
	if (this != &other) {
		if (other.has_value()) 
		{
			m_value = std::make_unique<T>(*other.m_value);
		}
		else 
		{
			m_value.reset();
		}
	}
	return *this;
}

//---------------------------------------------------------------------------

