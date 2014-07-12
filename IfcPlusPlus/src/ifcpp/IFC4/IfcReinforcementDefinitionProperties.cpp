/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcLabel.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcReinforcementDefinitionProperties.h"
#include "include/IfcRelAssociates.h"
#include "include/IfcRelDeclares.h"
#include "include/IfcRelDefinesByProperties.h"
#include "include/IfcRelDefinesByTemplate.h"
#include "include/IfcSectionReinforcementProperties.h"
#include "include/IfcText.h"
#include "include/IfcTypeObject.h"

// ENTITY IfcReinforcementDefinitionProperties 
IfcReinforcementDefinitionProperties::IfcReinforcementDefinitionProperties() {}
IfcReinforcementDefinitionProperties::IfcReinforcementDefinitionProperties( int id ) { m_id = id; }
IfcReinforcementDefinitionProperties::~IfcReinforcementDefinitionProperties() {}

// method setEntity takes over all attributes from another instance of the class
void IfcReinforcementDefinitionProperties::setEntity( shared_ptr<IfcPPEntity> other_entity )
{
	shared_ptr<IfcReinforcementDefinitionProperties> other = dynamic_pointer_cast<IfcReinforcementDefinitionProperties>(other_entity);
	if( !other) { return; }
	m_GlobalId = other->m_GlobalId;
	m_OwnerHistory = other->m_OwnerHistory;
	m_Name = other->m_Name;
	m_Description = other->m_Description;
	m_DefinitionType = other->m_DefinitionType;
	m_ReinforcementSectionDefinitions = other->m_ReinforcementSectionDefinitions;
}
void IfcReinforcementDefinitionProperties::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCREINFORCEMENTDEFINITIONPROPERTIES" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_DefinitionType ) { m_DefinitionType->getStepParameter( stream ); } else { stream << "$"; }
	stream << ",";
	writeEntityList( stream, m_ReinforcementSectionDefinitions );
	stream << ");";
}
void IfcReinforcementDefinitionProperties::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcReinforcementDefinitionProperties::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReinforcementDefinitionProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcReinforcementDefinitionProperties, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_GlobalId = IfcGloballyUniqueId::createObjectFromStepData( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromStepData( args[2] );
	m_Description = IfcText::createObjectFromStepData( args[3] );
	m_DefinitionType = IfcLabel::createObjectFromStepData( args[4] );
	readEntityReferenceList( args[5], m_ReinforcementSectionDefinitions, map );
}
void IfcReinforcementDefinitionProperties::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcPreDefinedPropertySet::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "DefinitionType", m_DefinitionType ) );
	shared_ptr<IfcPPAttributeObjectVector> ReinforcementSectionDefinitions_vec_object( new  IfcPPAttributeObjectVector() );
	std::copy( m_ReinforcementSectionDefinitions.begin(), m_ReinforcementSectionDefinitions.end(), std::back_inserter( ReinforcementSectionDefinitions_vec_object->m_vec ) );
	vec_attributes.push_back( std::make_pair( "ReinforcementSectionDefinitions", ReinforcementSectionDefinitions_vec_object ) );
}
void IfcReinforcementDefinitionProperties::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
}
void IfcReinforcementDefinitionProperties::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcPreDefinedPropertySet::setInverseCounterparts( ptr_self_entity );
}
void IfcReinforcementDefinitionProperties::unlinkSelf()
{
	IfcPreDefinedPropertySet::unlinkSelf();
}
