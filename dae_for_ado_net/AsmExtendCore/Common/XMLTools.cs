using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.IO;
using System.Globalization;

namespace AsmExtendCore
{
    static class XMLTools
    {
        private static class EncodeHelper
        {
            // In system.web there is a tool class "HttpUtility" and we need use decode and encode method at this class
            // But some restrictive environment, we cannot add system.web reference
            public static string HtmlDecode(string strValue) { return strValue; /* return System.Web.HttpUtility.HtmlDecode(strValue); */ }
            public static string HtmlEncode(string strValue) { return strValue; /* return System.Web.HttpUtility.HtmlEncode(strValue); */ }
        }

        static public string GetXMLSingleNodeAttributeValue(XmlNode obParentNode, string strChidNodeName, XmlNamespaceManager xmlnsMgr, string nodeAttributes)
        {
            if (null != obParentNode)
            {
                XmlNode xmlNode = obParentNode.SelectSingleNode(strChidNodeName, xmlnsMgr);
                if (xmlNode != null)
                {
                    return GetAttributeValue(xmlNode.Attributes, nodeAttributes, 3);
                }
            }
            return "";
        }
        static public XmlNode SelectSingleNode(XmlNode obParentNode, string strChidNodeName, XmlNamespaceManager xmlnsMgr, string strXmlNsPrefix)
        {
            if (null != obParentNode)
            {
                if (null == xmlnsMgr)
                {
                    return obParentNode.SelectSingleNode(strChidNodeName);
                }
                else
                {
                    return obParentNode.SelectSingleNode("//" + strXmlNsPrefix + ":" + strChidNodeName, xmlnsMgr);
                }
                
            }
            return null;
        }

        // nType: 0(InnerText), 1(InnerXml), 2(OuterXml)
        static public string GetXMLSingleNodeText(XmlNode obParentNode, string strChidNodeName, int nType = 0)
        {
            if (null != obParentNode)
            {
                return GetXMLNodeText(obParentNode.SelectSingleNode(strChidNodeName), nType);
            }
            return "";
        }
        // nType: 0(InnerText), 1(InnerXml), 2(OuterXml)
        static public string GetXMLNodeText(XmlNode obNode, int nType = 0)
        {
            if (null != obNode)
            {
                if (0 == nType)
                {
                    return EncodeHelper.HtmlDecode(obNode.InnerText);
                }
                else if (1 == nType)
                {
                    return EncodeHelper.HtmlDecode(obNode.InnerXml);
                }
                else if (2 == nType)
                {
                    return EncodeHelper.HtmlDecode(obNode.OuterXml);
                }
            }
            return "";
        }
        static public XmlElement CreateElement(XmlDocument xmlDoc, XmlNode obParentNode, string strName, string strValue, params string[] szStrAttr)
        {
            XmlElement obElement = xmlDoc.CreateElement(strName);
            int nLength = szStrAttr.Length - (szStrAttr.Length % 2);
            for (int i = 0; i < nLength; i += 2)
            {
               obElement.SetAttribute(szStrAttr[i], szStrAttr[i + 1]);
            }
            obElement.InnerText = EncodeHelper.HtmlEncode(strValue);
            obParentNode.AppendChild(obElement);
            return obElement;
        }
        static public bool SetAttributeValue(XmlDocument xmlDoc, XmlNode obCurNode, string strAttrName, string strAttrValue)
        {
            bool bRet = false;
            if ((null != xmlDoc) && (null != obCurNode) && (!string.IsNullOrWhiteSpace(strAttrName)) && (!string.IsNullOrWhiteSpace(strAttrValue)))
            {
                XmlAttributeCollection xmlAttributes = obCurNode.Attributes;
                XmlAttribute xmlAttr = xmlAttributes[strAttrName];
                if (null == xmlAttr)
                {
                    XmlNode xmlAttrNew = xmlDoc.CreateNode(XmlNodeType.Attribute, strAttrName, null);
                    xmlAttrNew.Value = EncodeHelper.HtmlEncode(strAttrValue);
                    obCurNode.Attributes.SetNamedItem(xmlAttrNew);
                }
                else
                {
                    xmlAttr.Value = EncodeHelper.HtmlEncode(strAttrValue);
                }
                bRet = true;
            }
            return bRet;
        }
        // nType: 0(InnerText), 1(InnerXml), 2(OuterXml),3(Value)
        static public string GetAttributeValue(XmlAttributeCollection xmlAttributes, string strAttrName, int nType = 0)
        {
            string strAttrValue = "";
            if (null != xmlAttributes)
            {
                XmlAttribute xmlAttr = xmlAttributes[strAttrName];
                if (null != xmlAttr)
                {
                    if (0 == nType)
                    {
                        strAttrValue = EncodeHelper.HtmlDecode(xmlAttr.InnerText);
                    }
                    else if (1 == nType)
                    {
                        strAttrValue = EncodeHelper.HtmlDecode(xmlAttr.InnerXml);
                    }
                    else if (2 == nType)
                    {
                        strAttrValue = EncodeHelper.HtmlDecode(xmlAttr.OuterXml);
                    }
                    else if (3 == nType)
                    {
                        strAttrValue = EncodeHelper.HtmlDecode(xmlAttr.Value);
                    }
                }
            }
            return strAttrValue;
        }
        // nType: value 0(InnerText), 1(InnerXml), 2(OuterXml),3(Value)
        static public Dictionary<string, string> GetAllAttributes(XmlAttributeCollection xmlAttributes, int nType = 0)
        {
            Dictionary<string, string> dirAttribures = new Dictionary<string,string>();
            if (null != xmlAttributes)
            {
                foreach (XmlAttribute xmlAttr in xmlAttributes)
                {
                    if (0 == nType)
                    {
                        dirAttribures.Add(xmlAttr.Name, EncodeHelper.HtmlDecode(xmlAttr.InnerText));
                    }
                    else if (1 == nType)
                    {
                        dirAttribures.Add(xmlAttr.Name, EncodeHelper.HtmlDecode(xmlAttr.InnerXml));
                    }
                    else if (2 == nType)
                    {
                        dirAttribures.Add(xmlAttr.Name, EncodeHelper.HtmlDecode(xmlAttr.OuterXml));
                    }
                    else if (3 == nType)
                    {
                        dirAttribures.Add(xmlAttr.Name, EncodeHelper.HtmlDecode(xmlAttr.Value));
                    }
                }
            }
            return dirAttribures;
        }
        static public Dictionary<string, string> GetAllSubNodesInfo(XmlNode obParentNode)
        {
            Dictionary<string, string> dicSubNodesInfo = new Dictionary<string,string>();
            if (null != obParentNode)
            {
                foreach (XmlNode obSubNode in obParentNode.ChildNodes)
                {
                    if (XmlNodeType.Comment != obSubNode.NodeType)
                    {
                        CommonHelper.AddKeyValuesToDic(dicSubNodesInfo, obSubNode.Name, GetXMLNodeText(obSubNode));
                    }
                }
            }
            return dicSubNodesInfo;
        }
        static public List<XmlNode> GetAllSubNodes(XmlNode obParentNode, string strSubNodeName)
        {
            List<XmlNode> lsSubNodesInfo = new List<XmlNode>();
            if (null != obParentNode)
            {
                foreach (XmlNode obSubNode in obParentNode.ChildNodes)
                {
                    if (XmlNodeType.Comment != obSubNode.NodeType)
                    {
                        if (String.IsNullOrEmpty(strSubNodeName))
                        {
                            lsSubNodesInfo.Add(obSubNode);
                        }
                        else
                        {
                            if (String.Equals(strSubNodeName, obSubNode.Name))
                            {
                                lsSubNodesInfo.Add(obSubNode);
                            }
                        }
                    }
                }
            }
            return lsSubNodesInfo;
        }
    }
}
