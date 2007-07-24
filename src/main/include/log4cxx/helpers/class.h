/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_HELPERS_CLASS_H
#define _LOG4CXX_HELPERS_CLASS_H

#include <log4cxx/logstring.h>
#include <log4cxx/helpers/objectptr.h>
#include <map>

namespace log4cxx
{
        namespace helpers
        {
                class Object;
                typedef ObjectPtrT<Object> ObjectPtr;


                class LOG4CXX_EXPORT Class
                {
                public:
                        virtual ~Class();
                        virtual ObjectPtr newInstance() const;
                        const LogString toString() const;
                        virtual const logchar* getName() const = 0;
                        static const Class& forName(const LogString& className);
                        static bool registerClass(const Class& newClass);

                protected:
                        Class();

                private:
                        Class(const Class&);
                        Class& operator=(const Class&);
                        typedef std::map<LogString, const Class *> ClassMap;
                        static ClassMap& getRegistry();
                        static void registerClasses();
                };
        }  // namespace log4cxx
} // namespace helper

#endif //_LOG4CXX_HELPERS_CLASS_H