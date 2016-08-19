using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace CSharpLibrary
{
    public class CustomArgs : EventArgs
    {
        public CustomArgs(string message)
        {
            Message = message;
        }

        public string Message { get; private set; }
    }
}
