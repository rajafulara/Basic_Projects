import requests

def fetch_weather_data(city_name):
    api_key = 'YOUR_API_KEY'  # Replace with your API key from OpenWeatherMap
    base_url = 'http://api.openweathermap.org/data/2.5/weather'
    params = {
        'q': city_name,
        'units': 'metric',  # or 'imperial' for Fahrenheit
        'appid': api_key
    }

    try:
        response = requests.get(base_url, params=params)
        data = response.json()

        if data['cod'] == 200:
            print(f"Weather in {city_name}:")
            weather_desc = data['weather'][0]['description'].capitalize()
            temp = data['main']['temp']
            feels_like = data['main']['feels_like']
            humidity = data['main']['humidity']
            wind_speed = data['wind']['speed']

            print(f"Description: {weather_desc}")
            print(f"Temperature: {temp}°C")
            print(f"Feels like: {feels_like}°C")
            print(f"Humidity: {humidity}%")
            print(f"Wind Speed: {wind_speed} m/s")
        else:
            print(f"Error: {data['message']}")
    
    except Exception as e:
        print(f"Error fetching weather data: {str(e)}")

# Example usage:
if __name__ == "__main__":
    city = input("Enter city name: ")
    fetch_weather_data(city)
