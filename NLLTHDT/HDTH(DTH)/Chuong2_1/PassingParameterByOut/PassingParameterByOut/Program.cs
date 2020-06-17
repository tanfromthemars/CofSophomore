using System;

public class Time
{
    private int Hour;
    private int Minute;
    private int Second;
    public void Display()
    {
        Console.WriteLine("(0) : (1) : (2)", Hour, Minute, Second);
    }
    public void GetTime(out int h, out int m, out int s)
    {
        h = Hour;
        m = Minute;
        s = Second;
    }
    public Time(System.DateTime dt)
    {
        Hour = dt.Hour;
        Minute = dt.Minute;
        Second = dt.Second;
    }
}

public class PassingParameterByOut
{
    static void Main()
    {
        DateTime currentTime = DateTime.Now;
        Time t = new Time(currentTime);
        t.Display();

        int theHour;
        int theMinute;
        int theSecond;

        t.GetTime(out theHour, out theMinute, out theSecond);
        Console.WriteLine("Current time: {0}:{1}:{2}", theHour, theMinute, theSecond);
        Console.ReadLine();
    }
}