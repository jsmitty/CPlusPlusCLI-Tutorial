using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpLibrary
{
    public class ExampleObject
    {
        private int _trackedInt;

        public ExampleObject()
        {
            _trackedInt = 0;
        }

        /// <summary>
        /// Prints message to console.
        /// 0 - Performed without error
        /// 1 - String was null or empty
        /// </summary>
        /// <param name="message"></param>
        /// <returns></returns>
        public int Print(string message)
        {
            if (string.IsNullOrEmpty(message))
                return 1;

            Console.WriteLine(message);
            return 0;
        }

        public int Add(int num)
        {
            _trackedInt += num;
            checkAndFireEvent();

            return _trackedInt;
        }

        public int Subtract(int num)
        {
            _trackedInt -= num;
            checkAndFireEvent();

            return _trackedInt;
        }

        public event EventHandler EvenNumberAchieved;
        public event EventHandler OddNumberAchieved;

        /// <summary>
        /// fires a simple event in order to test them in unmanaged code
        /// </summary>
        private void checkAndFireEvent()
        {
            if (_trackedInt % 2 == 0)
            {
                if (EvenNumberAchieved != null)
                    EvenNumberAchieved(this, EventArgs.Empty);
            }
            else
            {
                if (OddNumberAchieved != null)
                    OddNumberAchieved(this, EventArgs.Empty);
            }
        }
    }
}
